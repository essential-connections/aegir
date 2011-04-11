<?php

/**
 * Implementation of hook_drush_command().
 */
function eit_aegir_drush_command() {
  //$items = array();
  /*$items['provision vget'] = array(
    'description' => 'disable ads for a site.',
    'arguments' => array(
      'name' => 'A string to filter the variables by.  Only variables beginning with the string will be listed.',
    ),
    'examples' => array(
      'drush vget' => 'List all variables and values.',
      'drush vget user' => 'List all variables beginning with the string "user".',
    ),
    'aliases' => array('vget2'),
  );*/
  $items['provision disableads'] = array(
    'description' => 'Disable ads for a site.',
    'arguments' => array(
      'domain.com' => dt('The domain.'),
      '/path/to/platform' => dt('The platform.')),
      'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_ROOT
  );
  $items['provision enableads'] = array(
    'description' => 'Enable ads for a site.',
    'arguments' => array(
      'domain.com' => dt('The domain.'),
      '/path/to/platform' => dt('The platform.')),
      'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_ROOT
  );

  return $items;
}

function drush_eit_aegir_provision_disableads() {
  //if (drush_confirm("This command will replace your crontab for this user. continue?")) {
    //variable_set('hosting_dispatch_enabled', FALSE);
    // attempt to run the dispatch command, to make sure it runs without the queue being enabled.
    //variable_set('hosting_dispatch_enabled', TRUE);
    //drush_print(_hosting_dispatch_cmd());
    //exec(_hosting_dispatch_cmd(), $return, $code);
    //variable_set('hosting_dispatch_enabled', FALSE);
    //$return = join("\n", $return);
    //$data = unserialize($return);
    //if ($code == DRUSH_SUCCESS) {
    //  variable_set('hosting_dispatch_enabled', TRUE);
    //  drush_log(t("Dispatch command was run successfully"), 'success');
    //  _hosting_setup_cron();
    //}
    //else {
    //  drush_set_error('DRUSH_FRAMEWORK_ERROR', dt("Dispatch command could not be run. Returned: \n@return", array('@return' => $return)));
    //}
    //if (drush_get_error()) {
    //  drush_log(t("The command did not complete successfully, please fix the issues and re-run this script"), 'error');
    //}
  //}
  //drush_print('disableads callback');
  drush_log('callback disableads');
}
function drush_eit_aegir_provision_enableads() {
  drush_log('callback enableads');
}


function drush_eit_aegir_pre_hosting_task($task) {
  $task =& drush_get_context('HOSTING_TASK');
  if ($task->ref->type == 'site') {
    if ($task->task_type == 'disableads') {
      //$task->args[2] = $task->task_args['new_name'];
      //$platform = node_load($task->task_args['target_platform']);
      //$task->args[3] = $platform->publish_path;
      drush_log('pre disableads');
      
    }else if($task->task_type == 'enableads'){
      drush_log('pre enableads');
      
    }
  }
}

function eit_aegir_post_hosting_disableads_task($task, $data) {
  if ($task->ref->type == 'site') {
    //foreach($task->args as $k => $v){
    //drush_log($k.' : '.$v);
    //}

    $platform = node_load($task->ref->platform);
    $uri = $task->args[0];
    drush_log('post disableads:'. $platform->publish_path.' : '.$uri);

    exec('/usr/bin/php /var/aegir/drush/drush.php vset eit_ads 0 --backend --root='.$platform->publish_path.'  --uri='.$uri, $return, $code);
    //$return = join("\n", $return);
    //$data = unserialize($return);
    if ($code == DRUSH_SUCCESS) {
      drush_log(t("Dispatch command was run successfully - "), 'success');

      $task->ref->field_ad['0']['value'] = 0;
      //$task->ref->verified = mktime();
      $task->ref->no_verify = TRUE;
      node_save($task->ref);
    }
    else {
      drush_set_error('DRUSH_FRAMEWORK_ERROR', dt("Dispatch command could not be run. Returned: \n@return", array('@return' => $return)));
    }
    if (drush_get_error()) {
      drush_log(t("The command did not complete successfully, please fix the issues and re-run this script"), 'error');
    }
  }
}
function eit_aegir_post_hosting_enableads_task($task, $data) {
  if ($task->ref->type == 'site') {
    $platform = node_load($task->ref->platform);
    $uri = $task->args[0];
    drush_log('post enableads:'. $platform->publish_path.' : '.$uri);

    exec('/usr/bin/php /var/aegir/drush/drush.php vset eit_ads 1 --backend --root='.$platform->publish_path.'  --uri='.$uri, $return, $code);
    //$return = join("\n", $return);
    //$data = unserialize($return);
    if ($code == DRUSH_SUCCESS) {
      drush_log(t("Dispatch command was run successfully"), 'success');

      $task->ref->field_ad['0']['value'] = 1;
      //$task->ref->verified = mktime();
      $task->ref->no_verify = TRUE;
      node_save($task->ref);
    }
    else {
      drush_set_error('DRUSH_FRAMEWORK_ERROR', dt("Dispatch command could not be run. Returned: \n@return", array('@return' => $return)));
    }
    if (drush_get_error()) {
      drush_log(t("The command did not complete successfully, please fix the issues and re-run this script"), 'error');
    }
  }
}


<?php
// $Id: provision_welcome_mail.inc,v 1.2 2008/10/21 18:48:04 adrian Exp $
/**
 * @file
 * Define subject and body text for an email to the admin user created
 * for a site. 
 *
 * At the very least you will want to send them the one-time login url, !login_url.
 */

$mail = array();

$mail['subject'] = st('Your new site !site is ready.');
$mail['body'] = st("Your new site !site is ready.

The login information for your website is different than the login for your account at essential-connections.com.
This is done for security reasons and for your protection. 

The default user name for your website account is admin, and you will create a password when you log in using the link below.

You can now login to your site by clicking on this link or copying it into your browser:

!login_url

Once you have logged in, you will be redirected to !edit_uri so you can change your password. This is a one-time login so it.s important for you to enter your own password at this time. Be sure to keep your password secure to
protect your site.

When you visit your website for the first time it may take an extra few seconds to load while the site builds the initial caches. You may also see some system messages.

Note: If you are not automatically taken to the page to change your password, do not leave the site.
Click on My Account on the black bar menu at the top of the page. When you are in My Account, go to
the Edit tab to enter a new password and then click Save at the bottom of the page.

To get started setting up your site view our guide at http://help.essential-connections.com/content/getting-started 
which you can also find in your personal menu at the top of your site under \"Help\".

Thank you for becoming an Essential-Connections member.

Your Essential-Connections team");

?>

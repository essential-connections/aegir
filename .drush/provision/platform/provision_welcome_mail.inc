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

When you visit your website for the first time it may take an extra few seconds to load while the site builds the initial caches. You may also see some system messages. These are temporary.

Follow these steps to get started.

1. To log in for the first time use this link or copy it into your browser:

!login_url

This is a one-time login directly into your website account so you can create your own password.  The default user name for your website account is admin. You can leave it as is, or change your user name at any time.

Note: If you are not automatically taken to the page to change your password, do not leave the site.  Click on My Account on the black menu bar at the top of the page. When you are in My Account, go to the Edit tab to enter a new password and then click Save at the bottom of the page.

2. Be sure to keep your password secure to protect your site.

3. To get started setting up your site, go to Help/Getting Started on the black menu bar. (This menu bar is only viewable by logged in users.) Follow the Getting Started guide.

To find out how to do a specific task, click on Help for an index of all help files that you can search to find the instructions you need. 

As you are setting up your site or adding to it, look for a [Help for this page] link at the top of most pages to get specific help for that page.

We truly want your experience with Essential-Connections to be exceptional. 

Thank you for becoming a member.

Your Essential-Connections team");

?>

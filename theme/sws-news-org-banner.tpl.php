<?
// $Id$

/**
 * @file sws-news-org-banner.tpl.php
 * Default theme implementation to display news organization banner/logo.
 *
 * Available variables:
 * - $node: The node object.
 * - $size: User-selected imagecache preset.
 * - $banner: themed banner image 
 * - $banner_link: banner linked to news org website
 * - $website: org website
 *
 * @see template_preprocess_sws_news_org_banner()
 */
?>
<?php if (!empty($banner_link)) : ?>
  <div class="news-clip-banner"><?php print $banner_link ?></div>
<?php elseif (!empty($banner)) : ?>
  <div class="news-clip-banner"><?php print $banner ?></div>
<?php endif; ?>

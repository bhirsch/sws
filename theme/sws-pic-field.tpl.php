<?
// $Id$

/**
 * @file sws-pic-field.tpl.php
 * Default theme implementation to display the value of a pic field.
 *
 * Available variables:
 * - $node: The node object.
 * - $output: Default output prepared by template filed. HTML of images
     wrapped individually in div tags. You can wrap the picture or whole set
     of pictures using this variable.
 * - $pics: Array of pictures, themed with user-selected imagecache preset.
 * - $size: User-selected imagecache preset.
 * - $align: User-selected alignment.
  *
 * @see template_preprocess_sws_pic()
 */
?>
<?php if (!empty($output)) : ?>
  <?php print $output  ?>
<?php endif; ?>

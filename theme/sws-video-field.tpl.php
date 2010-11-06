<?
// $Id$

/**
 * @file sws-video-field.tpl.php
 * Default theme implementation to display the value of a video field.
 *
 * Available variables:
 * - $node: The node object.
 * - $video: HTML to embed video.
 * - $align: User-selected alignment for video, handled in CSS.
 * - $video_url: URL of the video.
  *
 * @see template_preprocess_sws_video()
 */
?>
<?php if (!empty($video)) : ?>
  <?php print "<div class='video video-$align'> $video </div>" ?>
<?php endif; ?>

<?php
/**
 * @file mobile_app_generator.admin.inc
 */

function mag_settings_form($form, &$form_state) {
  $form = array();

  $form['mag_export_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Path for generated files'),
    '#description' => t('Path where generated files are stored. This can include a file scheme, e.g. public://mobile or s3://mobile.'),
    '#default_value' => variable_get('mag_export_path', 'sites/all/export'),
    '#size' => 60,
    '#required' => TRUE,
  );

  $form['mag_regexp'] = array(
    '#type' => 'textfield',
    '#title' => t('Regexp for saving directories'),
    '#description' => t('Regexp used for scanning module directories for files to export.'),
    '#default_value' => variable_get('mag_regexp', '/^.*\.(jpg|png|js|css)/'),
    '#size' => 60,
    '#required' => TRUE,
  );

  $form['mag_export_menu'] = array(
    '#type' => 'select',
    '#title' => t('Menu to Export'),
    '#description' => t('The menu used for exporting the nodes.'),
    '#options' => menu_get_menus(TRUE),
    '#required' => TRUE,
    '#default_value' => variable_get('mag_export_menu', 'main-menu'),
  );

  $form['generate'] = array(
    '#type' => 'submit',
    '#value' => t('Generate Mobile App'),
    '#submit' => array('mag_do_export') 
  );

  return system_settings_form($form);
}

function mag_do_export(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/mag/generate';
}

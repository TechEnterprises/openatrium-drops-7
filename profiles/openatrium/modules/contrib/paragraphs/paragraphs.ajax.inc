<?php

/**
 * @file
 * Provides callbacks for ajax endpoints.
 */

/**
 * Page callback to handle AJAX for editing a paragraphs item.
 *
 * This is a direct page callback. The actual job of deleting the item is
 * done in the submit handler for the button, so all we really need to
 * do is process the form and then generate output. We generate this
 * output by doing a replace command on the id of the entire form element.
 */
function paragraphs_edit_js() {
  // drupal_html_id() very helpfully ensures that all html IDS are unique
  // on a page. Unfortunately what it doesn't realize is that the IDs
  // we are generating are going to replace IDs that already exist, so
  // this actually works against us.
  if (isset($_POST['ajax_html_ids'])) {
    // Store the html ids.
    $subject = array_shift($_POST['ajax_html_ids']);
    unset($_POST['ajax_html_ids']);
  }

  list($form, $form_state) = ajax_get_form();
  drupal_process_form($form['#form_id'], $form, $form_state);

  // Get the information on what we're removing.
  $button = $form_state['triggering_element'];
  // Go two levels up in the form, to the whole widget.
  $element = drupal_array_get_nested_value($form, array_slice($button['#array_parents'], 0, -4));

  // The id of the element we want to replace.
  $target_id = $element['#id'];

  // The target id is wrong if we are in a modal. We need to search through the
  // html ids we stored earlier. If we find a match: e.g., [TARGET_ID]--2, then
  // we know we are in a modal so we switch out the original id of the element
  // with the new one that exists in the modal.
  if (isset($subject)) {
    $pattern = '/,(' . $target_id . '--[0-9]' . '),/';
    if (preg_match($pattern, $subject, $matches)) {
      if (isset($matches[1])) {
        $target_id = $matches[1];
      }
    }
  }

  // Set the id of the element to the target id.
  $element['#id'] = $target_id;

  // Now send back the proper AJAX command to replace it.
  $return = array(
    '#type' => 'ajax',
    '#commands' => array(
      ajax_command_replace('#' . $target_id, drupal_render($element))
    ),
  );

  // Because we're doing this ourselves, messages aren't automatic. We have
  // to add them.
  $messages = theme('status_messages');
  if ($messages) {
    $return['#commands'][] = ajax_command_prepend('#' . $target_id, $messages);
  }

  return $return;
}

/**
 * Page callback to handle AJAX for collapse a paragraphs item.
 *
 * This is a direct page callback. The actual job of deleting the item is
 * done in the submit handler for the button, so all we really need to
 * do is process the form and then generate output. We generate this
 * output by doing a replace command on the id of the entire form element.
 */
function paragraphs_collapse_js() {
  // drupal_html_id() very helpfully ensures that all html IDS are unique
  // on a page. Unfortunately what it doesn't realize is that the IDs
  // we are generating are going to replace IDs that already exist, so
  // this actually works against us.
  if (isset($_POST['ajax_html_ids'])) {
    // Store the html ids.
    $subject = array_shift($_POST['ajax_html_ids']);
    unset($_POST['ajax_html_ids']);
  }

  list($form, $form_state) = ajax_get_form();
  drupal_process_form($form['#form_id'], $form, $form_state);

  // Get the information on what we're removing.
  $button = $form_state['triggering_element'];
  // Go two levels up in the form, to the whole widget.
  $element = drupal_array_get_nested_value($form, array_slice($button['#array_parents'], 0, -4));

  // The id of the element we want to replace.
  $target_id = $element['#id'];

  // The target id is wrong if we are in a modal. We need to search through the
  // html ids we stored earlier. If we find a match: e.g., [TARGET_ID]--2, then
  // we know we are in a modal so we switch out the original id of the element
  // with the new one that exists in the modal.
  if (isset($subject)) {
    $pattern = '/,(' . $target_id . '--[0-9]' . '),/';
    if (preg_match($pattern, $subject, $matches)) {
      if (isset($matches[1])) {
        $target_id = $matches[1];
      }
    }
  }

  // Set the id of the element to the target id.
  $element['#id'] = $target_id;

  // Now send back the proper AJAX command to replace it.
  $return = array(
    '#type' => 'ajax',
    '#commands' => array(
      ajax_command_replace('#' . $target_id, drupal_render($element))
    ),
  );

  // Because we're doing this ourselves, messages aren't automatic. We have
  // to add them.
  $messages = theme('status_messages');
  if ($messages) {
    $return['#commands'][] = ajax_command_prepend('#' . $target_id, $messages);
  }

  return $return;
}

/**
 * Page callback to handle AJAX for removing a paragraphs item.
 *
 * This is a direct page callback. The actual job of deleting the item is
 * done in the submit handler for the button, so all we really need to
 * do is process the form and then generate output. We generate this
 * output by doing a replace command on the id of the entire form element.
 */
function paragraphs_remove_js() {
  // drupal_html_id() very helpfully ensures that all html IDS are unique
  // on a page. Unfortunately what it doesn't realize is that the IDs
  // we are generating are going to replace IDs that already exist, so
  // this actually works against us.
  if (isset($_POST['ajax_html_ids'])) {
    // Store the html ids.
    $subject = array_shift($_POST['ajax_html_ids']);
    unset($_POST['ajax_html_ids']);
  }

  list($form, $form_state) = ajax_get_form();
  drupal_process_form($form['#form_id'], $form, $form_state);

  // Get the information on what we're removing.
  $button = $form_state['triggering_element'];
  // Go two levels up in the form, to the whole widget.
  $element = drupal_array_get_nested_value($form, array_slice($button['#array_parents'], 0, -4));

  // The id of the element we want to replace.
  $target_id = $element['#id'];

  // The target id is wrong if we are in a modal. We need to search through the
  // html ids we stored earlier. If we find a match: e.g., [TARGET_ID]--2, then
  // we know we are in a modal so we switch out the original id of the element
  // with the new one that exists in the modal.
  if (isset($subject)) {
    $pattern = '/,(' . $target_id . '--[0-9]' . '),/';
    if (preg_match($pattern, $subject, $matches)) {
      if (isset($matches[1])) {
        $target_id = $matches[1];
      }
    }
  }

  // Set the id of the element to the target id.
  $element['#id'] = $target_id;

  // Now send back the proper AJAX command to replace it.
  $return = array(
    '#type' => 'ajax',
    '#commands' => array(
      ajax_command_replace('#' . $target_id, drupal_render($element))
    ),
  );

  // Because we're doing this ourselves, messages aren't automatic. We have
  // to add them.
  $messages = theme('status_messages');
  if ($messages) {
    $return['#commands'][] = ajax_command_prepend('#' . $target_id, $messages);
  }

  return $return;
}


/**
 * Page callback to handle AJAX for removing a paragraphs item.
 *
 * This is a direct page callback. The actual job of deleting the item is
 * done in the submit handler for the button, so all we really need to
 * do is process the form and then generate output. We generate this
 * output by doing a replace command on the id of the entire form element.
 */
function paragraphs_deleteconfirm_js() {
  // drupal_html_id() very helpfully ensures that all html IDS are unique
  // on a page. Unfortunately what it doesn't realize is that the IDs
  // we are generating are going to replace IDs that already exist, so
  // this actually works against us.
  if (isset($_POST['ajax_html_ids'])) {
    // Store the html ids.
    $subject = array_shift($_POST['ajax_html_ids']);
    unset($_POST['ajax_html_ids']);
  }

  list($form, $form_state) = ajax_get_form();
  drupal_process_form($form['#form_id'], $form, $form_state);

  // Get the information on what we're removing.
  $button = $form_state['triggering_element'];
  // Go two levels up in the form, to the whole widget.
  $element = drupal_array_get_nested_value($form, array_slice($button['#array_parents'], 0, -4));

  // The id of the element we want to replace.
  $target_id = $element['#id'];

  // The target id is wrong if we are in a modal. We need to search through the
  // html ids we stored earlier. If we find a match: e.g., [TARGET_ID]--2, then
  // we know we are in a modal so we switch out the original id of the element
  // with the new one that exists in the modal.
  if (isset($subject)) {
    $pattern = '/,(' . $target_id . '--[0-9]' . '),/';
    if (preg_match($pattern, $subject, $matches)) {
      if (isset($matches[1])) {
        $target_id = $matches[1];
      }
    }
  }

  // Set the id of the element to the target id.
  $element['#id'] = $target_id;

  // Now send back the proper AJAX command to replace it.
  $return = array(
    '#type' => 'ajax',
    '#commands' => array(
      ajax_command_replace('#' . $target_id, drupal_render($element))
    ),
  );

  // Because we're doing this ourselves, messages aren't automatic. We have
  // to add them.
  $messages = theme('status_messages');
  if ($messages) {
    $return['#commands'][] = ajax_command_prepend('#' . $target_id, $messages);
  }

  return $return;
}

/**
 * Page callback to handle AJAX for restoring a paragraphs item.
 *
 * This is a direct page callback. The actual job of deleting the item is
 * done in the submit handler for the button, so all we really need to
 * do is process the form and then generate output. We generate this
 * output by doing a replace command on the id of the entire form element.
 */
function paragraphs_restore_js() {
  // drupal_html_id() very helpfully ensures that all html IDS are unique
  // on a page. Unfortunately what it doesn't realize is that the IDs
  // we are generating are going to replace IDs that already exist, so
  // this actually works against us.
  if (isset($_POST['ajax_html_ids'])) {
    unset($_POST['ajax_html_ids']);
  }

  list($form, $form_state) = ajax_get_form();
  drupal_process_form($form['#form_id'], $form, $form_state);

  // Get the information on what we're removing.
  $button = $form_state['triggering_element'];
  // Go two levels up in the form, to the whole widget.
  $element = drupal_array_get_nested_value($form, array_slice($button['#array_parents'], 0, -4));
  // Now send back the proper AJAX command to replace it.
  $return = array(
    '#type' => 'ajax',
    '#commands' => array(
      ajax_command_replace('#' . $element['#id'], drupal_render($element))
    ),
  );

  // Because we're doing this ourselves, messages aren't automatic. We have
  // to add them.
  $messages = theme('status_messages');
  if ($messages) {
    $return['#commands'][] = ajax_command_prepend('#' . $element['#id'], $messages);
  }

  return $return;
}

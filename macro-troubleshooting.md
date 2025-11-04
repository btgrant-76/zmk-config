# Macro Troubleshooting

what's happening with the bracket inserts?

## Notes

- is this an issue with any of the other macros?
- is it an issue outside the IntelliJ editor?

### Boards

#### Le Chiffre

- fails
  - `parens_semi_ls`:  both keys are mod-taps and are same-hand; both keys are mod-taps and are same-hand; easy to reproduce when typing S and A quickly; Both S and A are tap-holds
  - `bracket_ls`: both keys are mod-taps and are same-hand
  - `curly_brace_semi_ls`:  easy to reproduce by typing S A quickly
- works:  the rest
 
#### le jlwffre

- works:  all
- fails:  none

## TODOs

- [ ] if the macros execute successfully from key presses, open a github issue on `zmk-leader-key`

### Done

- [x] sync up the contents of the two keymaps and flash before testing
- [x] go through all macros on both boards and see which ones freak out and which ones are fine
    - boards
    - [x] raise a question about what I'm observing in ZMK help
- [x] Assign the sequence macros to keys for the sequences are having issues

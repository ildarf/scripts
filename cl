#!/bin/bash

for i in {0..9};
do
	tmux select-pane -t $i
	tmux send-keys Escape
	tmux send-keys ":xa" Enter
	tmux kill-pane -a
done;

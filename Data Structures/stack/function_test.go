package main

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestPush(t *testing.T) {
	t.Run("When item is pushed", func(t *testing.T) {
		expectedStack := []int{1, 2, 3}
		stk := Stack{size: 5}
		t.Run("stack should be updated", func(t *testing.T) {
			stk.Push(1)
			stk.Push(2)
			stk.Push(3)
			assert.Equal(t, expectedStack, stk.stack)
		})
	})
}

func TestPop(t *testing.T) {
	t.Run("when item is popped", func(t *testing.T) {
		expected := 3
		stk := Stack{size: 5}
		t.Run("it should return last removed item", func(t *testing.T) {
			stk.Push(1)
			stk.Push(2)
			stk.Push(3)
			poppedElement := stk.Pop()
			assert.Equal(t, expected, poppedElement)
		})
	})

	t.Run("when stack is empty", func(t *testing.T) {
		expected := -1
		stk := Stack{size: 5}
		t.Run("it should return -1", func(t *testing.T) {
			poppedElement := stk.Pop()
			assert.Equal(t, expected, poppedElement)
		})
	})
}

package queue

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestEnqueue(t *testing.T) {
	t.Run("testing the enqueue operation", func(t *testing.T) {
		expected := true
		q := NewQueue(5)
		actual := q.Enqueue(1)
		assert.Equal(t, expected, actual)
	})
	t.Run("testing if queue is full", func(t *testing.T) {
		expected := false
		q := NewQueue(1)
		q.Enqueue(1)
		actual := q.Enqueue(2)
		assert.Equal(t, expected, actual)
	})
}

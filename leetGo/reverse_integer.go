package main

import (
	"fmt"
	"math"
)
// 7
func main() {
	fmt.Println(reverse(-123))
}

func reverse(x int) int {
	sums := 0

	for x != 0 {
		digit := x % 10
		sums = sums*10 + digit
		x = x / 10
	}

	if sums > math.MinInt32 && sums < math.MaxInt32 {
		return sums
	} else {
		return 0
	}
}
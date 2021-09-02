package main

import (
	"fmt"
	"reflect"
)

type demo struct {
	i int
}

func main() {
	s := "abcd"
	s1 := s + ".jpg"
	fmt.Println(s1)
	nums := []int{1, 2}
	nums2 := []int{1}
	var d demo
	d = demo{i: 1}
	b := demo{i: 2}
	fmt.Println(reflect.DeepEqual(d, b))
	fmt.Println(d == b)
	fmt.Println(reflect.DeepEqual(nums, nums2))
}

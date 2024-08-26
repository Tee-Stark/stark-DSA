package main

import "fmt"

func powerSet(arr []int) [][]int {
	lenArr := len(arr) - 1
	return poweSetRecursive(arr, lenArr)
}

func poweSetRecursive(arr []int, ptr int) [][]int {
	if ptr == -1 {
		innerSlice := []int{}
		return append([][]int{}, innerSlice)
	}
	val := arr[ptr]
	fmt.Printf("val == %v\n", val)

	new := [][]int{}
	curr := poweSetRecursive(arr, ptr-1)
	copy(new, curr)

	for _, v := range curr {
		v = append(v, val)
		new = append(new, v)
	}
	return append(curr, new...)
}

func main() {
	arr := []int{1, 2, 3, 4}
	// fmt.Println([][]int{[]int{1}})
	fmt.Println(powerSet(arr))
}

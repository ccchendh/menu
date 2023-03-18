package main

import "fmt"

func main() {
	menu()
}

func menu() {
	for {
		var cmd string
		fmt.Println("Please input a cmd: ")
		fmt.Scanln(&cmd)
		switch {
		case cmd == "help":
			fmt.Println("cmd list:\n")
			fmt.Println("help\n")
			fmt.Println("exit\n")
			fmt.Println("echo\n")
		case cmd == "exit":
			break
		case cmd == "echo":
			fmt.Scanln(&cmd)
			fmt.Println(cmd)
		default:
			fmt.Println("please input a valid cmd!\n")
		}
	}

}

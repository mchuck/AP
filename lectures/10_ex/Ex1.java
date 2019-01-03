/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package abstra10;

/**
 *
 * @author szymczak
 */
public class Ex1 {
    
    public static void run(){
        System.out.println("EX1");
         // TODO code application logic here
        Integer[] a = new Integer[2];
        a[0] = 1;
        a[1] = 2;
        for (Integer i : a) {
            System.out.print(i + " ");
        }
        System.out.println();
        swap(a, 0, 1);
        for (Integer i : a) {
            System.out.print(i + " ");
        }
        System.out.println();
    }
    
    public static <T> void swap(T[] a, int i, int j) {
        T temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

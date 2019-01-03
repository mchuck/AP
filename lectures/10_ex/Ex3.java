/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package abstra10;

//import abstra10.Ex2.NumberList;
import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 *
 * @author szymczak
 */
public class Ex3 {
 
    class NumberList<E extends Number> extends ArrayList<E>{
                
        public NumberList() {
            super();
        }
       
        private int compare(Number n1, Number n2) {
            BigDecimal b1 = new BigDecimal(n1.doubleValue());
            BigDecimal b2 = new BigDecimal(n2.doubleValue());
            return b1.compareTo(b2);
        }
       
        
        public E min() {
            E min = this.get(0);
            for(E elem : this) {
                if(compare(elem, min) < 0) {
                    min = elem;
                }
            }
            return min;
        }
        
        public E max() {
            E max = this.get(0);
            for(E elem : this) {
                if(compare(elem, max) > 0) {
                    max = elem;
                }
            }
            return max;
        }
        
        public BigDecimal sum() {
            BigDecimal sum = new BigDecimal(0);
            for(E elem : this) {
                sum = sum.add( new BigDecimal(elem.doubleValue()) );
            }
            return sum;
        }
        
        public double avg() {
            BigDecimal sum = sum();
            BigDecimal listSize = BigDecimal.valueOf(this.size());          
            return sum.doubleValue()/listSize.doubleValue();
        }
        
        public E mode() {
            E maxValue = null;
            int maxCount = 0;
            for(int i = 0; i < this.size(); i++) {
                int count = 0;
                for(int j = 0; j < this.size(); j++) {
                    if (this.get(j).equals(this.get(i))) ++count;
                }
                if (count > maxCount) {
                    maxCount = count;
                    maxValue = this.get(i);
                }
            }
            return maxValue;
        }
    }
    
    public NumberList<Number> mergeList(List<? extends Number> a, List<? extends Number> b){
        NumberList<Number> l=new NumberList<>();
        l.addAll(a);
        l.addAll(b);
        return l;
        
    }
    
    public void run(){
        System.out.println("Ex3");
        List<Integer> a=Arrays.asList(1,2,3,4);
        List<Double> b=Arrays.asList(1.1,2.2,3.3,4.4);
        NumberList<Number> l=mergeList(a,b);
        System.out.println(l.avg());
        
    }
}

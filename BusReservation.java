
import java.util.*;

class BusReservation extends Thread{
    int vacant=2,required;
    
    BusReservation(int r){
        required=r;
    }
    
    public synchronized void run(){
        System.out.println("Welcome "+Thread.currentThread().getName());
    System.out.println(vacant + " No. of seats remaining");
    
    if(required<=vacant){
        System.out.println(required+" Seats booked");
        
        vacant-=required;
        
        try{
            Thread.sleep(100);
        }
        catch(Exception e){}
}
else{
    System.out.println("All tickets booked");
}

    }
}



class Main{
    
    public static void main(String[] args){
        BusReservation br = new BusReservation(2);
        
        Thread t1=new Thread(br);
        Thread t2=new Thread(br);
        t1.setName("A");
        t2.setName("B");
        t1.start();
        t2.start();
    }
    
}
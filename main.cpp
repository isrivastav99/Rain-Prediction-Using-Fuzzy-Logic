#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Speed_Output{
public:
    float value;
    float slow_value;
    float fast_value;
    Speed_Output()
    {
        this->slow_value = 0;
        this->fast_value = 0;
    }
    void defuzzify(float f, float s)
    {
        this->fast_value = f;
        this->slow_value = s;
        // Maximum of slow speed = 25
        // Minimum of Fast speed = 75
        // Weighted mean calculation
        float final = (((25 * s) + (75 * f))/(s + f));
        this->value = final;

    }
};

/* 0-20 = Sunny
 * 20-40 -> Sunny, Partly Cloudy
 * 40-60 = Cloudy
 * 60-80 -> Cloudy, Overcast
 * 80-100 = Overcast*/
class Cover_Input{
public:
    float value;
    float sunny_value;
    float cloudy_value;
    float overcast_value;

    Cover_Input()
    {
        this->cloudy_value = 0;
        this->overcast_value = 0;
        this->sunny_value = 0;
    }
    void cover_fuzzify(float c)
    {
        this->value = c;
        if(c<=20)
        {
            this->sunny_value = 1;
        }
        else if(c>20 && c<40)
        {
            float temp1 = (40-c)/20;
            this->sunny_value = temp1;
            float temp2 = (c-20)/30;
            this->cloudy_value = temp2;
        }
        else if(c>=40 && c<=50)
        {
            this->cloudy_value = (c-20)/30;
        }
        else if(c>50 && c<=60)
        {
            this->cloudy_value = (80-c)/30;
        }
        else if(c>60 && c<80)
        {
            float temp1 = (80-c)/30;
            this->cloudy_value = temp1;
            float temp2 = (c-60)/20;
            this->overcast_value = temp2;

        }
        else if(c>=80)
        {
            this->overcast_value = 1;
        }
    }
};


/* 0-30F = Freezing
 * 30-50F -> Freezing, Cool
 * 50-70F -> Cool, Warm
 * 70-90F -> Warm, Hot
 * >90 = Hot */
class Temperature_Input{
public:
    float value;
    //All between 0-1
   /*
        <= 10   ---- poor       (cold)
        5-25    ---- low        (warm)
        20-40   ---- medium     (hot)
        35>=    ---- high       (very hot)
   */
    float low, poor, medium, high;
    

    Temperature_Input()
    {
        this->value = 0;
        this->poor = 0;
        this->low = 0;
        this->medium = 0;
        this->high = 0;
    }
    void temp_fuzzify(float t)
    {
        this->value = t;
        if(t<=5)
        {
            this->poor = 1;
        }
        else if(t>5 && t<=10)
        {
            float temp1 = (10 - t)/5;
            this->poor = temp1;
            float temp2 = (t-5)/5;
            this->low = temp2;
        }
        else if (t>10 && t<=20)
        {
            this->low = 1;
        }
        else if(t>20 && t<=25)
        {
            float temp1 = (50 - t)/20;
            this->low = temp1;
            float temp2 = (t-30)/20;
            this->medium = temp2;
        }
        else if (t>25 && t<=35)
        {
            this->medium = 1;
        }
        else if (t>35 && t<=40)
        {
            float temp1 = (40 - t)/5;
            this->medium = temp1;
            float temp2 = (t-35)/5;
            this->high = temp2;
        }
        else if (t>40)
        {
            this->hot = 1;
        }
    }

};
class Pressure_Input{
public:
    float value;
    //All between 0-1
   /*
    SEA LEVEL PRESSURE
        <= 1002   ---- poor       
        1000-1006    ---- low        
        1004-1010   ---- medium     
        1008>=    ---- high       
   */
    float low, poor, medium, high;
    

    Pressure_Input()
    {
        this->value = 0;
        this->poor = 0;
        this->low = 0;
        this->medium = 0;
        this->high = 0;
    }
    void press_fuzzify(float p)
    {
        this->value = p;
        if(p<=1000)
        {
            this->poor = 1;
        }
        else if(p>1000 && p<=1002)
        {
            float pre1 = (1002 - p)/2;
            this->poor = pre1;
            float pre2 = (p-1000)/2;
            this->low = pre2;
        }
        else if (p>1002 && p<=1004)
        {
            float low = 1;
        }
        else if(p>1004 && p<=1006)
        {
            float pre1 = (1006 - p)/2;
            this->low = pre1;
            float pre2 = (p-1004)/2;
            this->medium = pre2;
        }
        else if (p>1006 && p<=1008)
        {
            float medium = 1;
        }
        else if(p>1008 && p<=1010)
        {
            float pre1 = (1010 - p)/2;
            this->medium = pre1;
            float pre2 = (p-1006)/2;
            this->high = pre2;
        }
        else if (p>1010)
        {
            this->high = 1;
        }
    }

};
class Humidity_Input{
public:
    float value;
    //All between 0-1
   /*
    Humidity percentage
        <=    ---- poor       
        -    ---- low        
        -   ---- medium     
        >=    ---- high       
   */
    float low, poor, medium, high;
    

    Humidity_Input()
    {
        this->value = 0;
        this->poor = 0;
        this->low = 0;
        this->medium = 0;
        this->high = 0;
    }
    void hum_fuzzify(float h)
    {
        this->value = h;
        if(h<=30)
        {
            this->poor = 1;
        }
        else if(h>30 && h<=40)
        {
            float pre1 = (40 - h)/10;
            this->poor = pre1;
            float pre2 = (h-30)/10;
            this->low = pre2;
        }
        else if (h>40 && h<=50)
        {
            float low = 1;
        }
        else if(h>50 && h<=60)
        {
            float pre1 = (60 - h)/10;
            this->low = pre1;
            float pre2 = (h-50)/10;
            this->medium = pre2;
        }
        else if (h>60 && h<=70)
        {
            float medium = 1;
        }
        else if(h>70 && h<=80)
        {
            float pre1 = (80 - h)/10;
            this->medium = pre1;
            float pre2 = (h-70)/10;
            this->high = pre2;
        }
        else if (h>80)
        {
            this->high = 1;
        }
    }

};
/* Sunny *  Warm = Fast
 * Cloudy * Cool = Slow */

void Rule_Evaluate(Temperature_Input t, Pressure_Input p, Humidity_Input h)
{
    Rain_Output r;
    float rpoor=0, rmedium=0, rlow=0, rhigh = 0;
    if(h.high && t.poor && p.medium){
    
    }
    if(h.high && t.low && p.medium){
    
    }
    if(h.medium && t.low && p.medium){
    
    }
    if(h.high && t.poor && p.high){
    
    }
    if(h.medium && t.poor && p.high){
    
    }
   if(h.poor && t.poor && p.high){
    
   }
    if(h.low && t.medium && p.medium){
    
    } 
    // Only 2 rules
    // Only 2 output values
   /* Speed_Output s;
    float strength_fast = 0;
    float strength_slow = 0;
    if(t.warm_value && c.sunny_value)
    {
        strength_fast = min(t.warm_value,c.sunny_value);
    }
    if(t.cool_value && c.cloudy_value)
    {
        strength_slow = min(t.cool_value,c.cloudy_value);
    }*/
    s.defuzzify(strength_fast,strength_slow);
    cout<<s.slow_value<<endl;
    cout<<s.fast_value<<endl;
    cout<<s.value<<" Final";


}

int main() {
    Temperature_Input t;
    t.temp_fuzzify(65);
    cout<<t.warm_value<<endl;
    cout<<t.cool_value<<" Temp"<<endl;
    Cover_Input c;
    c.cover_fuzzify(25);
    cout<<c.sunny_value<<endl;
    cout<<c.cloudy_value<<" Cover"<<endl;
    Rule_Evaluate(t,c);





    return 0;
}

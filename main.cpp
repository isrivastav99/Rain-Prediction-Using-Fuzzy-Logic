#include<bits/stdc++.h>
using namespace std;
class RainRate_Output{
public:
    float value;
    float poor_value;
    float low_value;
    float medium_value;
    float high_value;
    float extreme_value;
    RainRate_Output()
    {
        this->low_value = 0;
        this->poor_value = 0;
        this->medium_value = 0;
        this->high_value = 0;
        this->extreme_value = 0;
    }
    void defuzzify(float l, float p, float m, float h, float e )
    {
        this->medium_value = m;
        this->low_value = l;
        this->poor_value = p;
        this->high_value = h;
        this->extreme_value = e;

        // Weighted mean calculation
        float final = (((5 * p) + (11* l) + (21 * m) + (40 * h) + (65 * e))/(p + l + m + h + e));
        this->value = final;

    }
};

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
        if(t<=10)
        {
            this->poor = 1;
        }
        else if(t>10 && t<20)
        {
            float temp1 = (20 - t)/10;
            this->poor = temp1;
            float temp2 = (t-10)/10;
            this->low = temp2;
        }
        else if (t==20)
        {
            this->low = 1;
        }
        else if(t>20 && t<30)
        {
            float temp1 = (30 - t)/10;
            this->low = temp1;
            float temp2 = (t-20)/10;
            this->medium = temp2;
        }
        else if (t==30)
        {
            this->medium = 1;
        }
        else if (t>30 && t<40)
        {
            float temp1 = (40 - t)/10;
            this->medium = temp1;
            float temp2 = (t-30)/10;
            this->high = temp2;
        }
        else if (t>=40)
        {
            this->high = 1;
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
    void press_fuzzify(float p) {
        this->value = p;
        if (p <= 1000) {
            this->poor = 1;
        } else if (p > 1000 && p < 1003) {
            float pre1 = (1003 - p) / 3;
            this->poor = pre1;
            float pre2 = (p - 1000) / 3;
            this->low = pre2;
        } else if (p == 1003) {
            this->low = 1;
        } else if (p > 1003 && p < 1006) {
            float pre1 = (1006 - p) / 3;
            this->low = pre1;
            float pre2 = (p - 1003) / 3;
            this->medium = pre2;
        } else if (p == 1006) {
            this->medium = 1;
        } else if (p > 1006 && p < 1009) {
            float pre1 = (1009 - p) / 3;
            this->medium = pre1;
            float pre2 = (p - 1006) / 3;
            this->high = pre2;
        } else if (p >= 1009) {
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
    void hum_fuzzify(float h) {
        this->value = h;
        if (h <= 30) {
            this->poor = 1;
        } else if (h > 30 && h < 50) {
            float pre1 = (50 - h) / 20;
            this->poor = pre1;
            float pre2 = (h - 30) / 20;
            this->low = pre2;
        } else if (h == 50) {
            this->low = 1;
        } else if (h > 50 && h < 70) {
            float pre1 = (70 - h) / 20;
            this->low = pre1;
            float pre2 = (h - 50) / 20;
            this->medium = pre2;
        } else if (h == 70) {
            this->medium = 1;
        } else if (h > 70 && h < 90) {
            float pre1 = (90 - h) / 20;
            this->medium = pre1;
            float pre2 = (h - 70) / 20;
            this->high = pre2;
        } else if (h >= 90) {
            this->high = 1;
        }
    }

};
/* Sunny *  Warm = Fast
 * Cloudy * Cool = Slow */

void Rule_Evaluate(Temperature_Input t, Pressure_Input p, Humidity_Input h)
{
    RainRate_Output r;
    float rpoor=0, rmedium=0, rlow=0, rhigh = 0, rextreme = 0;
    //Humidity = poor
    if(h.poor && t.low && p.high){
        rpoor = min(h.poor, min(t.low, p.high));
    }
    if(h.poor && t.low && p.medium){
        rpoor = min(h.poor, min(t.low, p.medium));
    }
    if(h.poor && t.low &&  p.low){
        rpoor = min(h.poor, min(t.low, p.low));
    }
    if(h.poor && t.medium && p.high){
        rpoor = min(h.poor, min(t.medium, p.high));
    }
    if(h.poor && t.medium && p.medium){
        rpoor = min(h.poor, min(t.medium, p.medium));
    }
    if(h.poor && t.medium && p.low){
        rpoor = min(h.poor, min(t.medium, p.low));
    }

    //humidity = low
    if(h.low && t.medium && p.medium){
        rpoor = min(h.low, min(t.medium, p.low));
    }
    if(h.low && t.medium && p.medium){
        rpoor = min(h.low, min(t.medium, p.medium));
    }
    if(h.low && t.medium && p.medium){
        rpoor = min(h.low, min(t.medium, p.high));
    }
    if(h.low && t.low && p.low){
        rpoor = min(h.low, min(t.low, p.low));
    }
    if(h.low && t.low && p.medium){
        rmedium = min(h.low, min(t.low, p.medium));
    }
    if(h.low &&t.low && p.high){
        rlow = min(h.low, min(t.low, p.high));
    }


    if(h.medium && t.low && p.medium){
        rextreme = min(h.medium, min(t.low, p.medium));
    }

    if(h.medium && t.poor && p.high){
        rlow = min(h.medium, min(t.poor, p.high));
    }

    if(h.medium && t.low && p.high){
        rhigh = min(h.medium, min(t.low, p.high));
    }
    if(h.high && t.poor && p.medium){
        rlow = min(h.high, min(t.poor, p.medium));
    }
    if(h.high && t.low && p.medium){
        rpoor = min(h.high, min(t.poor, p.medium));
    }
    if(h.high && t.poor && p.high){
        rmedium = min(h.high, min(t.poor, p.high));
    }
    r.defuzzify(rpoor, rlow, rmedium, rhigh, rextreme);
    cout<<"Defuzzified Rain Rate : "<<r.value<<endl;
}

int main(int argc, char** argv) {
    Temperature_Input t;
    t.temp_fuzzify(stof(argv[1]));
    //cout<<t.low<<endl;
    //cout<<t.medium;
    //cout<<t.cool_value<<" Temp"<<endl;
    Humidity_Input h;
    h.hum_fuzzify(stof(argv[2]));
    //cout<<h.medium<<endl;
    //cout<<c.cloudy_value<<" Cover"<<endl;
    Pressure_Input p;
    p.press_fuzzify(stof(argv[3]));
    //cout<<p.medium<<endl;
    Rule_Evaluate(t,p,h);

    return 0;
}

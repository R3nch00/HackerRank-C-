#include<bits/stdc++.h>
using namespace std;
class Box{
    private : int l,b,h;
    public :
         Box(){l=b=h=0;}
            Box(int length,int breadth,int height){l=length,b=breadth;h=height;}
                Box(const Box& B){ l=B.l;b=B.b;h=B.h;}
    int getLength(){return l;} int getBreadth(){return b;} int getHeight(){return h;}
    long MeasureVolume(){return ((long)l*b*h);}
    friend bool operator < (Box& b1,Box& b2){
        if((b1.l<b2.l)||(b1.l==b2.l&&b1.b<b2.b)||(b1.l==b2.l&&b1.b==b2.b&&b1.h<b2.h)) return(true);
        else return(false); }
    friend ostream& operator<<(ostream& s,Box& b1){
        s<<b1.l<<" "<<b1.b<<" "<<b1.h; return s;
    }
};
void check2(){
    int i,n; cin>>n; Box temp;
        for(i=0;i<n;i++){ int type; cin>>type;
            switch(type){
                case 1:{cout<<temp<<endl;} break;
                case 2:{int l,b,h; cin>>l>>b>>h; Box NewBox(l,b,h); temp=NewBox; cout<<temp<<endl;} break;
                case 3:{int l,b,h; cin>>l>>b>>h; Box NewBox(l,b,h); (temp<NewBox) ? cout<<"Lesser\n":cout<<"Greater\n";} break;
                case 4:{cout<<temp.MeasureVolume()<<endl;} break;
                case 5:{Box NewBox(temp); cout<<NewBox<<endl;} break; }
    }
}
int main(){
check2();
}

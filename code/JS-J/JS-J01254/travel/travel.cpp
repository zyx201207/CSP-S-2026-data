#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
   // cout<<c1<<" "<<s1<<" "<<c2<<" "<<s2<<"\n";
    string x1,y1,x2,y2;
    x1=s1.substr(0,2);
    y1=s1[2];
    x2=s2.substr(0,2);
    y2=s2[2];
   // cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<"\n";
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    else{
        cout<< "1";
    }
    if(x1!=x2){
        cout<<"000";
        return 0;
    }
    else{
        cout<<"1";
    }
    if((y1=="A"&&y2=="B")||(y1=="B"&&y2=="A")||
       (y1=="A"&&y2=="C")||(y1=="C"&&y2=="A")||
       (y1=="B"&&y2=="C")||(y1=="C"&&y2=="B")||
       (y1=="D"&&y2=="F")||(y1=="F"&&y2=="D"))cout<<"1";
    else{
        cout<<"00";
        return 0;
    }

    if((y1=="A"&&y2=="B")||(y1=="B"&&y2=="A")||
       (y1=="B"&&y2=="C")||(y1=="C"&&y2=="B")||
       (y1=="D"&&y2=="F")||(y1=="F"&&y2=="D")) cout<<"1";
    else{
        cout<<"0";
        return 0;
    }
    return 0;
}

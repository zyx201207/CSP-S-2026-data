#include<bits/stdc++.h>
using namespace std;
int main(){

freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);

string c1,s1,c2,s2;
bool a=0,b=0,c=0,d=0,left1=1,left2=1;


cin>>c1[0]>>c1[1];
cin>>s1[0]>>s1[1]>>s1[2];
cin>>c2[0]>>c2[1];
cin>>s2[0]>>s2[1]>>s2[2];

if((s1[2]=='D')||(s1[2]=='E')){
    left1=0;
}

if((s2[2]=='D')||(s2[2]=='E')){
    left2=0;
}




if((c1[0]==c2[0])&&(c1[1]==c2[1])){
    a=1;

    if((s1[0]==s2[0])&&(s1[1]==s2[1])){
    b=1;

    if(left1==left2){
        c=1;
        int x1,x2;
        x1=s1[2]-'A';
        x2=s2[2]-'A';

        if((x1-x2==1)||(x1-x2==-1)){
            d=1;
        }



    }


}

}



cout<<a<<b<<c<<d;








return 0;
}

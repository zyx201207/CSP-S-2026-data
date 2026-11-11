#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
   string c1,s1,c2,s2,n,a1,b1,a2,b2;
   cin>>c1>>s1>>c2>>s2;
    a=s1.size();
    b=s2.size();
    for(int i=0;i<a-1;i++){
        a1+=s1[i];
        b1+=s2[i];

    }
     for(int i=a-1;i<a;i++){
        a2+=s1[i];
        b2+=s2[i];

    }
   if(c1==c2){
        n+="1";
   }
    else{
        n+="0";
    }
    if(a1==b1){
        n+="1";
    }
    else{
        n+="0";
    }
    if((a2=="D"&&b2=="F")||(a2=="F"&&b2=="D")||(a2=="A"&&b2=="B")||(a2=="A"&&b2=="C")||(a2=="B"&&b2=="C")||(a2=="B"&&b2=="A")||(a2=="C"&&b2=="A")||(a2=="C"&&b2=="B")){
        n+="1";
    }
    else{
        n+="0";
    }

 if((a2=="D"&&b2=="F")||(a2=="F"&&b2=="D")||(a2=="A"&&b2=="B")||(a2=="B"&&b2=="C")||(a2=="B"&&b2=="A")||(a2=="C"&&b2=="B")){
        n+="1";
    }
    else{
        n+="0";
    }


    cout<<n;

    return 0;
}

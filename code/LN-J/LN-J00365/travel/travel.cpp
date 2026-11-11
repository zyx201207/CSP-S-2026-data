#include<bits/stdc++.h>
using namespace std;
string r1,r2,x1,x2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r1>>r2>>x1>>x2;
    if(r2[2]=='D')r2[2]++;
    if(x2[2]=='D')x2[2]++;
    if(r1==x1){
        cout<<1;
        if(r2[0]==x2[0] and r2[1]==x2[1]){
           cout<<1;
           if(r2[2]<'D' and x2[2]<'D' or r2[2]>'D' and x2[2]>'D'){
               cout<<1;
               if(abs(r2[2]-x2[2])==1){
                   cout<<1;
               }else{
                   cout<<0;
               }
           }else{
               cout<<0<<0;
           }
        }else{
            cout<<0<<0<<0;
        }
    }else{
        cout<<0<<0<<0<<0;
    }


    return 0;
}

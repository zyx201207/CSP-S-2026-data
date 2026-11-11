#include<bits/stdc++.h>
using namespace std;
int ans[4];
int a,b;
string a1,b1;
int main(){
   freopen("travel.in","r",stdin);
   freopen("travel.out","w",stdout);
   cin>>a>>a1>>b>>b1;
   if(a==b){
    ans[0]=1;
    string a2,b2;
    a2+=a1[0];
    a2+=a1[1];
    b2+=b1[0];
    b2+=b1[1];
    char f=a1[2];
    char g=b1[2];
    if(a2==b2){
        ans[1]=1;
        if(f>='A' && f<='C'){
            if(g>='A'&& g<='C'){
                ans[2]=1;
                if(abs(a1[2]-b1[2])<2)
                    ans[3]=1;
            }
        }
        else if(g=='D'|| g=='F'){
            ans[2]=1;
            ans[3]=1;
        }
    }

   }
   for(int i=0;i<4;i++){
       cout<<ans[i];
   }
   return 0;
}

#include <bits/stdc++.h>
using namespace std;
int h[5]={0,0,0,0};
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
 ios::sync_with_stdio(false);
 cin.tie(nullptr);

    int b,c;
    string a1,a2,b1,b2;

    cin>>a1>>a2>>b1>>b2;
    if(a1==b1){
        h[0]=1;
        if(a2[0]==b2[0]&&a2[1]==b2[1]){
                h[1]=1;
              if(b2[2]+a2[2]==138||(b2[2]+a2[2]<=133&&b2[2]-a2[2]!=3)){
                h[2]=1;
                if(a2[2]+1==b2[2]||b2[2]+1==a2[2]||b2[2]+a2[2]==138){
                    h[3]=1;
                }
            }
        }

    }
    for(int i=0;i<=3;i++){
        cout<<h[i];
    }





}

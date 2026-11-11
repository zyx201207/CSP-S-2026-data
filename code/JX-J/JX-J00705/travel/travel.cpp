#include<bits/stdc++.h>
using namespace std;
int a[4]={0,0,0,0};
string s1,c1,s2,c2;
string d="ABC",f="DF";
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        a[0]=1;
    }
    else{
        cout<<0000;
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        a[1]=1;
        int ans=0;
        for(int i=0;i<3;i++){
            if(s1[2]==d[i]||s2[2]==d[i]){
                ans++;
            }
        }
        if(ans==2){
            a[2]=1;
        }
        if(abs(s1[2]-s2[2])==1){
            a[3]=1;
        }
        if(a[2]!=1){
            int sum=0;
            for(int i=0;i<2;i++){
                if(s1[2]==f[i]||s2[2]==f[i]){
                    sum++;
                }
            }
            if(sum==2)a[2]=1;
            if(abs(s1[2]-s2[2])==1){
                a[3]=1;
            }
        }
    }
    for(int i=0;i<4;i++){
        cout<<a[i];
    }
    return 0;
}

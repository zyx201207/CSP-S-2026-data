#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,f;
    cin>>a>>c>>b>>f;
    if(a==b&&(a!="01"||a!="016"))
        cout<<"1";
    else
        cout<<"0";
    int v=0;
    for(int i=0;i<3;i++){
        if(c[i]==f[i])
            v++;
    }
    if(v==3)
        cout<<"000";
    else{
    int num=0;
    for(int i=0;i<2;i++){
        if(c[i]!=f[i])
            num++;
    }
    if(num>=1||(c[0]+c[1]>104&&c[0]+c[1]<97)||(f[0]+f[1]>104&&f[0]+f[1]<97))
        cout<<"000";
    else{
    cout<<"1";
    int n=0,m=0;
    for(int i=1;i<3;i++){
        if(c[i]>=65&&c[i]<=67&&f[i]>=65&&f[i]<=67||c[i]>=68&&c[i]<=50&&f[i]>=68&&f[i]<=50){
            n+=1;
            if(c[i]+1==f[i]||f[i]+1==c[i])
                m+=1;
            }
        }
    if(n==1)
        cout<<"1";
    else cout<<"0";
    if(m==1)
        cout<<"1";
    else cout<<"0";
        }
    }
    return 0;
}

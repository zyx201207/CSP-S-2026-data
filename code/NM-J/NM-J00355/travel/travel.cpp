#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int z=0,x=0;
    double c,v;
    string a,s,d,f;
    cin>>a>>s>>d>>f;

    if(a==d){
        cout<<1;
    }else{
        cout<<0;
    }
    z=s[0]+s[1];
    x=f[0]+f[1];
    if(z==x){
        cout<<1;
    }
        else{
            cout<<0;
        }

        if(s[2]<='c'&&f[2]<='c'){
            cout<<1;
        }else{
            cout<<0;
        }

         c=s[2]-f[2];
        v=abs(c);
       if(v==1){
            cout<<1;
        }else{
        cout<<0;
        }

return 0;
}

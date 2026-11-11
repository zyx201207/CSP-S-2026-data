#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    string x1,x2,r,x,s;
    int q=0,w=0;
    cin>>x1>>r>>x2>>x;
    for(int i=0;i<=x1.size();i++){
        if(x1[i]>='0'&&x1[i]<='9'){
            q=q*10+x1[i];
        }
    }
    for(int i=0;i<=x2.size();i++){
        if(x2[i]>='0'&&x2[i]<='9'){
            w=w*10+x2[i];
        }
    }
    if(q==w){
        s+='1';
    }else{
        s+='0';
    }

    for(int i=0;i<=r.size();i++){
        if(r[i]>='0'&&r[i]<='9'){
            q=q*10+r[i];
        }
    }
    for(int i=0;i<=x.size();i++){
        if(x[i]>='0'&&x[i]<='9'){
            w=w*10+x[i];
        }
    }
    if(q==w){
        s+='1';
    }else{
        s+='0';
    }

    for(int i=2;i<=r.size();i++){
        if(r[i]>='A'&&r[i]<='C'&&x[i]>='A'&&x[i]<='C'){
            s+='1';
        }else{
            if(r[i]>='D'&&r[i]<='F'&&x[i]>='D'&&x[i]<='F'){
                s+='1';
            }else{
                s+='0';
            }
        }
    }
     for(int i=2;i<=r.size();i++){
        if(r[i]=='A'&&x[i]=='B'){
            s+='1';
        }else{
            if(r[i]=='B'&&x[i]<='A'&&x[i]>='C'){
                s+='1';
            }else{
                if(r[i]=='F'&&x[i]=='D'){
                    s+='1';
                }else{
                    if(r[i]=='D'&&x[i]=='f'){
                    s+='1';
                    }else{
                        s[i]+='0';
                    }
                }
            }
        }
    cout<<s;
    return 0;
}
}

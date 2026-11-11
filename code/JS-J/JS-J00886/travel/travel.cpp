#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    int e=1;
    for(int i=0;i<2;i++){
        if(a[i]!=c[i]){
            e=0;
        }
    }
    if(e==1){
        cout<<1;
        for(int i=0;i<2;i++){
            if(b[i]!=d[i]){
                e=0;
            }
        }
        if(e==1){
            cout<<1;
            if(b[2]>='A'&&b[2]<='C'){
                if(d[2]>='A'&&d[2]<='C'){
                    cout<<1;
                    if(b[2]-1==d[2]||b[2]+1==d[2]){
                        cout<<1;
                    }else{
                        cout<<0;
                    }
                }else{
                    cout<<0;
                    cout<<0;
                }
            }else{
                if(d[2]=='D'||d[2]=='F'){
                    cout<<1;
                    if(b[2]=='D'&&d[2]=='F'){
                        cout<<1;
                    }else if(b[2]=='F'&&d[2]=='D'){
                        cout<<1;
                    }else{
                        cout<<0;
                    }
                }else{
                    cout<<0;
                    cout<<0;
                }
            }
        }else{
            cout<<0;
            cout<<0;
            cout<<0;
        }
    }else{
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
    }
    return 0;
}

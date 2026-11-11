#include<bits/stdc++.h>
using namespace std;
string a[1005],b[1005],c[1005],d[1005];
char q[1005],w[1005],e[1005],r[1005];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>q>>w>>e>>r;
    for(int i=0;i<2;i++)a[i]=q[i];
    for(int i=0;i<3;i++)b[i]=w[i];
    for(int i=0;i<2;i++)c[i]=e[i];
    for(int i=0;i<3;i++)d[i]=r[i];
    if(a[0]==c[0]&&a[1]==c[1]){
        cout<<1;
        if(b[0]==d[0]&&b[1]==d[1]){
            cout<<1;
        }
        else{
            cout<<0<<0<<0;
            return 0;
        }
        if(b[2]=="A"){
            if(d[2]=="B"||d[2]=="C"){
                cout<<1;
            }
            else{
                cout<<0<<0;
                return 0;
            }
        }
        if(b[2]=="B"){
            if(d[2]=="A"||d[2]=="C"){
                cout<<1;
            }
            else{
                cout<<0<<0;
                return 0;
            }
        }
        if(b[2]=="C"){
            if(d[2]=="A"||d[2]=="B"){
                cout<<1;
            }
            else{
                cout<<0<<0;
                return 0;
            }
        }
        if(b[2]=="D"){
            if(d[2]=="F"){
                cout<<1;
            }
            else{
                cout<<0<<0;
                return 0;
            }
        }
        if(b[2]=="F"){
            if(d[2]=="D"){
                cout<<1;
            }
            else{
                cout<<0<<0;
                return 0;
            }
        }
        if(b[2]=="A"){
            if(d[2]=="B"){
                cout<<1;
            }
            else{
                cout<<0;
                return 0;
            }
        }
        if(b[2]=="B"){
            if(d[2]=="A"||d[2]=="C"){
                cout<<1;
            }
            else{
                cout<<0;
                return 0;
            }
        }
        if(b[2]=="C"){
            if(d[2]=="B"){
                cout<<1;
            }
            else{
                cout<<0;
                return 0;
            }
        }
        if(b[2]=="D"){
            if(d[2]=="F"){
                cout<<1;
            }
            else{
                cout<<0;
                return 0;
            }
        }
        if(b[2]=="F"){
            if(d[2]=="D"){
                cout<<1;
            }
            else{
                cout<<0;
                return 0;
            }
        }
    }
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    return 0;
}

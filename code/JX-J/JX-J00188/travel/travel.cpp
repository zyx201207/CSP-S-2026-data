#include<bits/stdc++.h>
using namespace std;
int n,m;
string p,q;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>p>>m>>q;
    if(n==m){
        cout<<1;
        if(p[1]==q[1]&&q[0]==p[0]){
            cout<<1;
            if(p[2]<='C'&&q[2]<='C'||p[2]>='D'&&q[2]>='D'){
                cout<<1;
                int s1=(p[0]-'0')*10+(p[1]-'0'),s2=(q[0]-'0')*10+(q[1]-'0'),s3=p[2]-'A',s4=q[2]-'A';
                if(abs(s1-s2)==1||abs(s3-s4)==1){
                    cout<<1;
                }else cout<<0;
            }else cout<<0<<0;
        }else cout<<0<<0<<0;
    }else cout<<0<<0<<0<<0;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string rc,rs,xc,xs;
    int h[10004];
    h['C']=1;h['A']=1;h['B']=1;
    h['D']=2;h['F']=2;
    cin>>rc>>rs>>xc>>xs;
    if(rc==xc){
        if(rs[0]+rs[1]==xs[0]+xs[1]){
            char r=rs[2],x=xs[2];
            if(h[r]==h[x]){
                if((r=='D'&&x=='F')||abs(r-x)==1 ){
                    cout<<"1111";
                }else{
                    cout<<"1110";
                }
            }else{
                cout<<"1100";
            }
        }else{
            cout<<"1000";
        }
    }else{
        cout<<"0000";
    }return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10,M=1e7+7;

signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s1,s2,c1,c2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<1;
            int t1=0,t2=0;
            char x1=s1[2],x2=s2[2];
            if(x1=='A'||x1=='B'||x1=='C'){
                t1=1;
            }if(x2=='A'||x2=='B'||x2=='C'){
                t2=1;
            }
            //cerr<<"abs"<<t1<<' '<<t2;
            if(t1==t2){
                cout<<1;
                if(abs(s1[2]-s2[2])==1)
                    cout<<1;
                else
                    cout<<0;
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;}

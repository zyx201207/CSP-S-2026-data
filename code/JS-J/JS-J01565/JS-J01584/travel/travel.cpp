#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
string a,b,c,d;
int f(char ch){
    if(ch=='A'){
        return 0;
    }
    if(ch=='B'){
        return 0;
    }
    if(ch=='C'){
        return 0;
    }
    if(ch=='D'){
        return 1;
    }
    if(ch=='F'){
        return 1;
    }
    return -1;
}
void solve(){
    cin>>a>>c>>b>>d;
    reverse(a.begin(),a.end());
    while(a.back()=='0'){
        a.pop_back();
    }
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    while(b.back()=='0'){
        b.pop_back();
    }
    reverse(b.begin(),b.end());
    int n=stoi(a),m=stoi(b);
    if(n==m){
        cout<<1;
        if(c[0]==d[0]&&c[1]==d[1]){
            cout<<1;
            int C=f(c[2]),D=f(d[2]);
            if(C==D){
                cout<<1;
                if(c[2]=='A'){
                    if(d[2]=='B'){
                        cout<<1;
                    }else{
                        cout<<0;
                    }
                }else if(c[2]=='B'){
                    if(d[2]=='A'||d[2]=='C'){
                        cout<<1;
                    }else{
                        cout<<0;
                    }
                }else if(c[2]=='C'){
                    if(d[2]=='B'){
                        cout<<1;
                    }else{
                        cout<<0;
                    }
                }else if(c[2]=='D'){
                    if(d[2]=='F'){
                        cout<<1;
                    }else{
                        cout<<0;
                    }
                }else if(c[2]=='F'){
                    if(d[2]=='D'){
                        cout<<1;
                    }else{
                        cout<<0;
                    }
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
}
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
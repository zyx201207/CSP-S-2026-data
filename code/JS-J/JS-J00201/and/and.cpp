#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+9;
int a[maxn],pos[maxn],sz[maxn];
int t[35];
int n,m;

string s;
void f(int x){
    if(x/2) f(x/2);
    if(x%2) s=s+"1";
    else s=s+"0";
}
string g(string s){
    while(s.size()<n) s="0"+s;
    return s;
}
void solve1(){
    int mx=0;
    for(int i=0;i<=(1<<n)-1;i++){
        s="";
        f(i);
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') cnt++;
        }
        if(cnt!=m) continue;
        //cout<<s<<endl;
        s=g(s);
        int ans=(1<<30)-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') continue;
            ans&=a[i+1];
        }
        mx=max(mx,ans);
    }
    cout<<mx;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    int mx=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    if(m==1){
        cout<<mx;
        return 0;
    }
    if(m==2){
        int mx=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                mx=max(mx,a[i]&a[j]);
            }
        }
        cout<<mx;
        return 0;
    }
    if(1){
        solve1();
        return 0;
    }

    return 0;
}

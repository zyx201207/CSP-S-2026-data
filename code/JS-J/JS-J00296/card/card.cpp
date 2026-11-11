#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
const int MAXN=500005;

int n,m,a[MAXN],b[MAXN];
bool f[MAXN],t=1;

signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]) t=0;
    }
    if(m<=2){
        for(int i=1;i<=n;i++){
            if(a[i]==a[n]) b[a[i]]++;
            else b[1]++,b[2]++;
        }
        cout<<b[1]<<" "<<b[2];
        return 0;
    }//this is for 13~14
    if(t){
        int op=a[1],cnt=1;
        for(int i=2;i<=n+1;i++){
            if(a[i]!=op) cout<<cnt<<" ",op=a[i];
            cnt++;
        }
        return 0;
    }//this is for sp A(20)
    for(int i=1;i<=n;i++){
        stack<int> st;
        for(int j=i;j<=n;j++){
            int u=a[j];
            if(!f[u]) st.push(u),f[u]=1;
            else{
                while(st.top()!=u) f[st.top()]=0,st.pop();
            }
        }
        for(int j=1;j<=m;j++) if(f[j]) b[j]++,f[j]=0;
    }
    for(int i=1;i<=m;i++) cout<<b[i]<<" ";
    return 0;
}

//id:JS-J00296
//This is the code of card.
//60 pts(1~14,20)
//1~4 samples correct.
//5,6 samples TLE.
//Last modified on Oct.31st 11:37
//password:Trick||Treat!
//failed for sp B

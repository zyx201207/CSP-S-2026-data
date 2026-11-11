#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll a[N],t[N];
ll n,m;
queue<ll> q;
ll f(int i){
    int b=0;
    int t1[N]={0};
    for(int j=i;j<=n;j++){
        bool ff=0;
        if(!q.empty()){
            if(t1[a[j]]==1){
                while(!q.empty()&&q.back()!=a[j]){
                    q.pop();
                }
            }else{
                q.push(a[j]);
                t1[a[j]]=1;
            }
        }else q.push(a[j]);
    }
    while(!q.empty()){
        t[q.front()]++;
        q.pop();
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=500&&m<=200){
        for(int i=1;i<=n;i++){
            f(i);
        }
        for(int i=1;i<=m;i++){
            cout<<t[i]<<' ';
        }
        return 0;
    }
    return 0;
}

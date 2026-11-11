#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int a[N],cnt[N];
bool f[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    stack<int> s;
    for(int t=1;t<=n;t++){

        for(int i=t;i<=n;i++){
            if(!f[a[i]]){
                s.push(a[i]);
                f[a[i]]=1;
            }else{
                while(!s.empty()){
                    int x=s.top();
                    s.pop();
                    if(x==a[i]){
                        s.push(x);
                        break;
                    }else f[x]=0;
                }
            }
        }
        while(!s.empty()){
            int x=s.top();
            s.pop();
            f[x]=0;
            cnt[x]++;
        }
    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
    cout<<'\n';
    return 0;
}

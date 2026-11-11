#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],ans[300005];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        stack<int> s;
        int f[300005];
        memset(f,0,sizeof f);
        for(int j=i-1;j<n;j++){
            if(f[a[j]]==0){
                s.push(a[j]);
                f[a[j]]=1;
            }else{
                while(s.top()!=a[j]){
                    s.pop();
                }

            }
        }
        while(!s.empty()){
            ans[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}


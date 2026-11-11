#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m;
int a[N];
int ans[M];
int last[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) last[a[i]]=i;
    for(int i=1;i<=n;i++){
        int idx=i;
        while(true){
            if(idx>n) break;
            ans[a[idx]]++;
            if(last[a[idx]]==idx) idx++;
            else idx=last[a[idx]]+1;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i];
        if(i!=m) cout<<" ";
    }
    cout<<"\n";
    return 0;
}

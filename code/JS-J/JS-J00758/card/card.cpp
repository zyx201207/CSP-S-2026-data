#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],t[N],ans[N];
unordered_map<long long,int>q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        int r=i-1;
        q.clear();
        for(int j=i;j<=n;j++){
            if(q[a[j]]==0){
                t[++r]=a[j];
                q[a[j]]=r;
            }
            else{
                r=q[a[j]];
            }
        }
        for(int k=i;k<=r;k++){
            ans[t[k]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
}
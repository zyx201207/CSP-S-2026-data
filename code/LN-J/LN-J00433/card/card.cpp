#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int n,m,a[N],la[N],ne[N],ans[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(la[a[i]]!=0){
            ne[la[a[i]]]=i;
        }
        la[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        int j=i;
        while(j<=n){
            while(ne[j]!=0)j=ne[j];
            ans[a[j]]++;
            j++;
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}

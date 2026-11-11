#include<bits/stdc++.h>
using namespace std;
int n,m,a[50000],cnt[50000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]+cnt[i-1]<<" ";
    //ji de shan diao zhu shi o
    return 0;
}

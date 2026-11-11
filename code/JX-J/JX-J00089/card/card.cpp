#include<bits/stdc++.h>
using namespace std;
long long a[500001],st[500001],top=0,ans[500001];
map<long long,bool>mp;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++){
        mp.clear();
        for(long long j=i;j<=n;j++){
            if(mp[a[j]]==1){
                for(long long k=top;k>0;k--){
                    if(st[k]==a[j]){
                        top=k;
                        break;
                    }
                    mp[st[k]]=0;
                }
            }
            else{
                mp[a[j]]=1;
                st[++top]=a[j];
            }
        }
        while(top>0){
            ans[st[top]]++;
            top--;
        }
    }
    for(long long i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
}

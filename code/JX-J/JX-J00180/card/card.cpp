#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[50005],t[30005],num[30005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=n;i>=1;--i){
        for(int j=1;j<=m;++j)t[j]=0;
        for(int j=i;j<=n;++j){
            if(t[a[j]]){
                for(int k=1;k<=m;++k)t[k]=0;
            }
            t[a[j]]=1;
        }
        for(int j=1;j<=m;++j){
            //cout<<t[j]<<" ";
            num[j]+=t[j];
        }//cout<<"\n";
    }
    for(int i=1;i<=m;++i)cout<<num[i]<<" ";
    return 0;
}

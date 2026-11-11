#include<bits/stdc++.h>
using namespace std;
const int N=5e5+16;
int a[N],lst[N],c[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,p=1;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        lst[a[i]]=i;
    }
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            if(j<lst[a[j]]){
                j=lst[a[j]]-1;
            }
            else{
                ++c[a[j]];
            }
        }
    }
    for(int i=1;i<=m;++i){
        cout<<c[i]<<' ';
    }
    return 0;
}
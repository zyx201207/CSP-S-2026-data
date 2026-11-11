#include<bits/stdc++.h>
using namespace std;
const int M=3e5+5,N=5e5+5;
int n,m,a[M],T,ans[M],a1[N];
void ch(){
    for(int i=1;i<=m;i++){
        if(a[i]>0)ans[i]++;
    }
    return ;
}
void fil(int l){
    for(int j=l;j<n;j++){
        a[a1[j]]-=j;
    }
    return ;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    if(m==1){
        cout<<n;
        return 0;
    }
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a1[i];
    while(T<n){
        for(int i=T;i<n;i++){
            if(a[a1[i]]>0){
                    fil(i);
                    a[a1[i]]=i;
            }
            a[a1[i]]+=i;
        }
        ch();
        T++;
        fill(a,a+M,0);
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}

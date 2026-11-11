#include<bits/stdc++.h>
using namespace std;
long long a[500001]={},t[300001]={},chu[500001]={},ans[500001]={},fl[300001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t[a[i]]++;
        chu[i]=i;
    }
    long long s=0;
    for(int i=1;i<=n;i++){
        if(t[a[i]]>1){
            t[a[i]]--;
            s++;
            fl[a[i]]++;

        }
        else if(t[a[i]]==1){
            //cout<<a[i]<<" ";
            s-=fl[a[i]];
            chu[i]-=s;
            ans[a[i]]=chu[i];
            t[a[i]]--;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}


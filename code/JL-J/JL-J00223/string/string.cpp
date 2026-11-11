#include<bits/stdc++.h>
using namespace std;
struct shu{
    int geshu;
    char zimu;
}a[200000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].geshu>>a[i].zimu;
    int l=1,r=n;
    while(l<r){
        if(a[l].zimu!=a[r].zimu){
            ans+=min(a[l].geshu,a[r].geshu);
            a[l].geshu-=min(a[l].geshu,a[r].geshu);
            a[r].geshu-=min(a[l].geshu,a[r].geshu);
        }else{
            a[l].geshu-=min(a[l].geshu,a[r].geshu);
            a[r].geshu-=min(a[l].geshu,a[r].geshu);
        }
        if(a[l].geshu==0)l++;
        if(a[r].geshu==0)r--;
    }
    cout<<ans;
    return 0;
}

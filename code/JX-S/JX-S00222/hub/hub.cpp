#include<bits/stdc++.h>
using namespace std;
long long n,m,len=1,ans=1;
long long a[600005];
int main(){
    freopen("crystal3.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    long long k=0,add;
    for(int i=1;i<n;i++){
        add=(a[i]-a[i-1])*len;
        if(k+add<=m){
            k+=add;
            len++;
        }
        else {
            while(k+add>m){
                k-=(a[i-1]-a[i-len]);
                add-=a[i]-a[i-1];
                len--;
            }
            k+=add;
            len++;
        }
        if(len>ans)ans=len;
    }
    printf("%lld",ans);
    return 0;
}

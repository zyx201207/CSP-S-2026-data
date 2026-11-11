#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[514514];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    long long num=0,minn=a[1],cnt=0,ans=0,l=1;
    for(int i=1;i<=n;i++){
        while(cnt+num*(a[i]-minn)>m){
            cnt-=minn-a[l];
            l++;
            num--;
        }
        if(cnt+num*(a[i]-minn)<=m){
            cnt+=num*(a[i]-minn);
            num++;
        }
        
        minn=a[i];
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
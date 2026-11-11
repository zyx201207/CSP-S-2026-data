#include <bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
long long a[500005],ch[500005],ch2[500005];//,sum[500005]
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
   //     sum[i]=sum[i-1]+a[i];
        ch[i]=a[i]-a[i-1];
    }

    int l=1,len=1;//len=r-l+1,r>=l,
    long long h=0;
    for(int r=1;r<n;){
        r++;
        h+=ch[r]*len;
        len++;
              //  cout<<l<<" "<<r<<" "<<h<<" "<<len<<endl;
        while(m<h&&l<=r){
            h-=a[r]-a[l];
            l++;
            len--;
        }
        if(len>ans){ans=len;}
    }
    cout<<ans;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,len,ans,mid;
int a[200050],sum[200050],b[200050];
char c[200050],d[200050];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;c[0]='&';
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
    for(int i=1;i<=n;i++)len+=a[i],sum[i]=sum[i-1]+a[i];
    if(!(len&1)){
        int l=lower_bound(sum+1,sum+n+1,len/2)-sum;
        mid=l+1;
        if(sum[l]==len/2){
            for(int i=n+1;i>l+1;i--)a[i]=a[i-1],c[i]=c[i-1];
            a[l+1]=1;c[l+1]='$';
            n++;
        }
        else{
            for(int i=n+2;i>l+2;i--)a[i]=a[i-2],c[i]=c[i-2];
            a[l+2]=sum[l]-len/2;c[l+2]=c[l];
            a[l+1]=1;c[l+1]='$';
            a[l]=len/2-sum[l-1];
            n+=2;
        }
        len++;
    }
    else{
        mid=lower_bound(sum+1,sum+n+1,len/2+1)-sum;
    }
//    cout<<mid;
//    for(int i=1;i<=n;i++)cout<<a[i]<<" "<<c[i]<<'\n';
    for(int i=1;i<=n;i++)b[n-i+1]=a[i],d[n-i+1]=c[i];
    int l=0,r=0,ls=0,rs=0;
    while(l<=n&&r<=n){
        if(ls>=rs+b[r+1]){
            r++;
            rs+=b[r];
            if(c[l]==d[r])continue;
            ans+=b[r];
        }
        else if(rs>=ls+a[l+1]){
            l++;
            ls+=a[l];
            if(c[l]==d[r])continue;
            ans+=a[l];
        }
        else{
            if(ls==rs){
                if(a[l+1]>b[r+1]){
                    r++;
                    if(c[l+1]!=d[r])ans+=b[r];
                    a[l+1]-=b[r];
                }
                else if(a[l+1]<b[r+1]){
                    l++;
                    if(c[l]!=d[r+1])ans+=a[l];
                    b[r+1]-=a[l];
                }
                else{
                    l++;r++;
                    if(c[l]!=d[r])ans+=a[l];
                }
            }
            else if(ls<rs){
                if(c[l+1]!=d[r])ans+=rs-ls;
                a[l+1]-=(rs-ls);
            }
            else{
                if(c[l]!=d[r+1])ans+=ls-rs;
                b[r+1]-=ls-rs;
            }
        }
    }
    cout<<ans/2;
    return 0;
}

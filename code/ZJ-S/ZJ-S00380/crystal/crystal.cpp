#include<bits/stdc++.h>
#define int long long
using namespace std;

namespace YJR{
    int read(){
        int ret=0,f=1;char ch=getchar();
        while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
        while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
        return ret*f;
    }
    int n,lst[500005],m,sum[500005],ans;
    signed main(){
        freopen("crystal.in","r",stdin);
        freopen("crystal.out","w",stdout);
        n=read(),m=read();
        for(int i=1;i<=n;i++) lst[i]=read();
        sort(lst+1,lst+1+n);
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+lst[i];
        for(int i=1;i<=n;i++){
            int l=1,r=i;
            while(l<=r){
                int mid=(l+r)/2;
                if((i-mid+1)*lst[i]-sum[i]+sum[mid-1]<=m) r=mid-1;
                else l=mid+1;
            }
            ans=max(ans,i-l+1);
        } 
        cout<<ans;
        return 0;
    }
}

signed main(){return YJR::main();}
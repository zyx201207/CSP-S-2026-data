#include<bits/stdc++.h>
using namespace std;
typedef long long la;
inline la read(){
    la ret,flag=1;char ch;
    while(!isdigit(ch=getchar()))if(ch=='-')flag=-1;
    ret=(la)ch-'0';
    while(isdigit(ch=getchar()))ret=ret*10+(la)ch-'0';
    return ret;
}
const int N=2e6+10,M=5e3+10;
la a[N],lst[N],ans[N],val[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c=read(),t=read();
    while(t--){
        la n=read(),m=read();
        for(int i=1;i<=n;i++)a[i]=read();
        for(int i=1;i<=n;i++){
            la l=1,r=n;
            while(l<r){
                la mid=(l+r)>>1;
                if(a[mid]>a[i]+m)r=mid-1;
                else if(a[mid]<=a[i]+m)l=mid+1;
            }
            if(a[l]<=a[i]+m)lst[i]=l;
            else lst[i]=l-1;
            val[i]=1;
        }
        printf("\n");
        for(int i=1;i<=n;i++){
            if(lst[i]==i){
                //
            }else if(lst[i]==i+1){
                val[i]++;
                val[i+1]++;
                ans[i+1]=ans[i];
            }else if(lst[i]==i+2){
                if(lst[i+1]==lst[i+2] && lst[i+2]!=i+2){
                    ans[lst[i+2]]+=val[i];
                }else{
                    val[i]=0;
                }
            }else{
                if(lst[lst[i]-1]==lst[lst[i]] && lst[lst[i-2]]!=lst[lst[i-1]){
                    ans[lst[lst[i]]]+=val[i];
                }
            }
        }
        la sum=0;
        for(int i=1;i<=n;i++)sum+=ans[i];
        printf("%lld\n",sum);
    }
    return 0;
}

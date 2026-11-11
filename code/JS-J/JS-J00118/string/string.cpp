#include <bits/stdc++.h>
using namespace std;
int n,a[2000001];
char c[2000001];
long long ans=0,l=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        cin>>a[i]>>c[i];
    for(int i=1;i<=n;i++)
        l+=a[i];
    int t1=1,t2=n;
    while(l>1){
        if(c[t1]==c[t2])
            if(a[t1]>a[t2])
                l-=a[t2]*2,a[t1]-=a[t2],t2--;
            else
                if(a[t1]<a[t2])
                    l-=a[t1]*2,a[t2]-=a[t1],t1++;
                else
                    l-=a[t1]*2,t1++,t2--;
        else{
            if(a[t1]>a[t2])
                l-=a[t2]*2,ans+=a[t2],a[t1]-=a[t2],t2--;
            else
                if(a[t1]<a[t2])
                    l-=a[t1]*2,ans+=a[t1],a[t2]-=a[t1],t1++;
                else
                    l-=a[t1]*2,ans+=a[t1],t1++,t2--;
        }
    }
    printf("%lld",ans);
    return 0;
}

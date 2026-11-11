
#include <bits/stdc++.h>

using namespace std;

int n;

int a[200005],c[200005],d[200005]={0};

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    long long sum=0;
    for(int i=1;i<=n;i++){
        scanf("%d %c",&a[i],&c[i]);
        sum+=(long long)a[i];
        d[i]=d[i-1]+a[i];
    }
    long long l=1,r=sum,i=1,j=n;
    long long ans=0;
    while(l<r){
   //     cout<<l<<" "<<(char)c[i]<<" "<<r<<" "<<(char)c[j]<<"\n";
        if(c[i]!=c[j]){
            ans++;
        }
        l++,r--;
        if(l>d[i]){
            i++;
        }
        if(n-r>d[n]-d[j-1]){
            j--;
        }
    }
    printf("%lld",ans);
    return 0;
}

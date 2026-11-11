
#include<bits/stdc++.h>
using namespace std;
int a[100005],n;
long long ans=0;
char s[100005];
int main(){
   //freopen("string.in","r",stdin);
  //  freopen("string.out","w",stdout);
   scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        char b;
        scanf("%c",&b);
        s[i]=b;
    }
    for(int i=1,j=n;i>=j;){
           if(s[i]!=s[j]){
        ans+=1LL*min(a[i],a[j]);
        }
        if(a[i]>=a[j]){
            a[i]-=a[j];
             a[n-i+1]=0;
             j--;
        }else{
            a[j]-=a[i];
            a[i]=0;
            i++;
        }
    }
    printf("%lld",ans);
    return 0;
}

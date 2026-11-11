#include<bits/stdc++.h>
using namespace std;
int a[200010];
char c[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        cin>>c[i];
    }
    int L=1,l=a[1],R=n,r=a[n];
    long long ans=0;
    while(L<R){
        int k=min(l,r);
        l-=k,r-=k;
        if(c[L]!=c[R])  ans+=k;
        if(l==0){
            L++;
            l=a[L];
        }else  if(r==0){
            R--;
            r=a[R];
        }
    }
    cout<<ans;
}

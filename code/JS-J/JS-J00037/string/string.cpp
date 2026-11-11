#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
long long a[maxn];
char c[maxn];
long long ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=1,j=n;i<=j;){
        if(c[i]!=c[j]){
            ans+=min(a[i],a[j]);
        }
        if(a[i]>=a[j]){
            a[i]-=a[j];
            a[j]=0;
        }else{
            a[j]-=a[i];
            a[i]=0;
        }
        if(a[i]==0)i++;
        if(a[j]==0)j--;
    }
    cout<<ans;
    return 0;
}

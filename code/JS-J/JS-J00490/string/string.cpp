#include<bits/stdc++.h>
#define int long long
#define N 200007 
using namespace std;
int n,ans;
int a[N],c[N];
char b[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        c[i]=a[i];
    }
    int l=1,r=n;
    while(l<r){
        if(min(c[l],c[r])==c[l]){
            if(b[l]!=b[r])ans=ans+c[l];
            c[r]-=c[l];
            l++;
        }else if(min(c[l],c[r])==c[r]){
            if(b[l]!=b[r]) ans=ans+c[r];
            c[l]-=c[r];
            r--; 
        }
    }
    cout<<ans<<endl;
    return 0;  
}
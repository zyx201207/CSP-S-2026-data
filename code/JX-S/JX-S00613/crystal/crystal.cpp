#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
int in(){
    int k=0,f=1;
    char c=getchar();
    while(!isdigit(c)){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(isdigit(c)){
        k=k*10+c-'0';
        c=getchar();
    }
    return k*f;
}

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n=in(),m=in();
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int sum=0,ans=1,x=1,j=1;
    for(int i=2;i<=n;i++){
        sum+=((a[i]-a[i-1])*(i-1)-(j-1)*(a[i]-a[i-1]));
        x++;
        while(sum>m&&j<=i){
            sum-=(a[i]-a[j]);
            j++;
            x--;
        }
        ans=max(x,ans);
    }
    cout<<ans;
    return 0;
}

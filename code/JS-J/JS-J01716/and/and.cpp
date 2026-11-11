#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxx=0,t,x=0,flag1=0,xb=1,ans,b[35],flag2=1;
void dfs(int last,int g,long long result){
    if(g==m){
        ans=max(ans,result);
        return;
    }
    for(int i=last+1;i<=n;i++){
        dfs(i,g+1,int(result*1ll&a[i]));
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    /*while(pow(2,x)<=n){
        if(pow(2,x)==n){
            flag1=x;
            break;
        }
        x++;
    }*/
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==1)t=a[i];
        else t=int(t&a[i]);
        maxx=max(a[i],maxx);
        x=0;
        while(pow(2,x)<=a[i]+1){
        if(pow(2,x)==n&&flag2==1){
            break;
        }
        x++;
    }
    if(pow(2,x)>a[i]+1)flag2=0;
    }
    if(m==1)cout<<maxx;
    else if(m==n)cout<<t;
    else if(flag1){
        int y=1,ans_1=0;
        x=0;
        while(pow(2,x)<=m)x++;
        for(int i=x+1;i<=flag1;i++){
            ans_1+=pow(2,i)-pow(2,i-1);
        }
        cout<<ans_1;
    }
    else if(m=2){
        int maxxx=0;
        for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)maxxx=max(maxxx,int(a[i]&a[j]));
        cout<<maxxx;
    }
    else if(flag2){
        sort(a+1,a+n+1);
        cout<<a[n-m+1];
    }
    else{
        dfs(0,0,pow(2,31)-1);
        cout<<ans;
    }
    return 0;
}

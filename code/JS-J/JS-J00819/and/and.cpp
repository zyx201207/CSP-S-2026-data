#include<bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;

int n,m,ans,sum=INT_MAX,maxn,tot;
int a[N];
bool flag,tiao;

bool cmp(int a,int b){
    return a>b;
}

void dfs(int x,int cnt,int andx){
    if(x==n+1){
        if(cnt==m){
            ans=max(ans,andx);
        }
        return ;
    }
    dfs(x+1,cnt+1,andx&a[x]);
    dfs(x+1,cnt,andx);
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        maxn=max(maxn,a[i]);
        if(i==1) tot=a[i];
        else tot&=a[i];
    }
    tiao=true;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=30;j++){
            if(a[i]==pow(2,j)-1){
                flag=true;
            }
        }
        if(!flag) tiao=false;
    }
    if(tiao==true){
        sort(a+1,a+n+1,cmp);
        cout<<a[m];
        return 0;
    }
    if(m==1){
        cout<<maxn;
        return 0;
    }
    else if(m==n){
        cout<<tot;
        return 0;
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }
    else if(m==n-1){
        int ans_xx=0;
        for(int i=1;i<=n;i++){
            ans=0;
            for(int j=1;j<=n;j++){
                if(j==i) continue;
                if(ans==0) ans=a[j];
                else ans&=a[j];
            }
            ans_xx=max(ans_xx,ans);
        }
        cout<<ans_xx;
        return 0;
    }
    dfs(1,0,sum);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

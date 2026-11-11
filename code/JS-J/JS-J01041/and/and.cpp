#include<bits/stdc++.h>
#define luogu using
#define jisuanjijiaoyu namespace
#define xinshengtai std

luogu jisuanjijiaoyu xinshengtai;
long long a[200050],ans,n,k;
int visit[200010];

long long lmax(long long a,long long b){
    return a>b?a:b;
}

void dp(int m,long long p){
    if(p<ans)return;
    if(m==k){
        ans=lmax(ans,p);
        return;
    }

    for(int i=1;i<=n;i++){
        if(visit[i]==0){
            visit[i]=1;
            if(m==0){
                dp(m+1,a[i]);
            }
            else{
                if(p&a[i]<ans)continue;
                dp(m+1,p&a[i]);
            }
            visit[i]=0;
        }
    }
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];

    if(n==k){
        ans=a[1];
        for(int i=2;i<=n;i++)ans=ans&a[i];
        cout<<ans<<endl;
        return 0;
    }

    if(n-1==k){
        ans=-1;
        long long ccf;
        for(int i=1;i<=n;i++){
            ccf=i==1?a[2]:a[1];
            for(int j=1;j<=n;j++){
                if(j==i)continue;
                ccf=ccf&a[j];
            }
            ans=lmax(ans,ccf);
        }
        cout<<ans<<endl;
        return 0;
    }

    dp(0,0);
    cout<<ans<<endl;
    return 0;
}
//55 pts maybe
//ccf v me 50

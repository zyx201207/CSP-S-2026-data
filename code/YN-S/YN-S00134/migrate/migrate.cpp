#include <bits/stdc++.h>
using namespace std;
const int N=2e6+114;
int n;
long long g;
long long x[N],to[N];
int ans;

int dfs(int now,int ed,int k){
    if(now==ed)
        return 1;
    if(k==0)
        return 0;
    int res=0;
    for(int i=now+1;i<=to[now];i++){
        res+=dfs(i,ed,k-1);
        if(res>2)
            return res;
    }
    return res;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>g;
        for(int i=1;i<=n;i++)
            cin>>x[i];
        if(n==1||n==2||n==3){
            cout<<0<<"\n";
            continue;
        }
        bool A=1;
        for(int i=2;i<n;i++)
            if(x[i]-x[i-1]!=x[i+1]-x[i]){
                A=0;
                break;
        }
//        cout<<A<<" ";
        if(A==1){
            int c=g/(x[2]-x[1]);
            if(c==0||c==1||n<=2*c-1){
                cout<<0<<"\n";
                continue;
            }
            cout<<n-(2*c-1)<<"\n";
            continue;
        }

        int far=1;
        for(int i=1;i<=n;i++){
            while(x[i]+g>=x[far]&&far<=n)
                far++;
            to[i]=far-1;
        }
        for(int l=1;l<=n;l++){
            for(int r=l+1;r<=n;r++){
                int now=l;
                int step=0;
                while(now<l){
                    now=to[now];
                    step++;
                }
                int res=dfs(l,r,step);
                if(res==2)
                    ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}

//    freopen("migrate.in","r",stdin);
//    freopen("migrate.out","w",stdout);

//freopen("migrate.in","r",stdin);
//freopen("migrate.out","w",stdout);

/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
不想打暴力了，事已至此，先睡觉吧……
*/

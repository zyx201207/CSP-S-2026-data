#include<bits/stdc++.h>
using namespace std;
int n;
int a[2000202];
int m;
int zo[30];
int ans=0;

inline void dfs(int i,int k){
    if(i==n+1){
            int cnt=0;
        for(int i=1;i<=n;i++){
            if(zo[i]==1){
                cnt++;
            }
        }

        if(cnt==m){
            int as=0,okk=0;
            for(int i=1;i<=n;i++){
                if(zo[i]&&!okk){
                    as=a[i];
                    okk=1;
                }else if(zo[i]){
                    as&=a[i];
                }
            }
            ans=max(ans,as);
        }
        return ;
    }
    zo[i+1]=0;
    dfs(i+1,0);
    zo[i+1]=1;
    dfs(i+1,1);
}

bool check(int x){
    while(x%2==0){
        x/=2;
    }
    if(x==1){
        return 1;
    }else{
        return 0;
    }
}
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=20){
        ans=-1e9;
        dfs(0,0);
        cout<<ans;
        return 0;
    }else{
        if(m==1){
            ans=-1e9;
            for(int i=1;i<=n;i++){
                ans=max(ans,a[i]);
            }
            cout<<ans;
            return 0;
        }else{
            if(m==n){
                ans=a[1];
                for(int i=2;i<=n;i++){
                    ans=ans&a[i];
                }
                cout<<ans;
                return 0;
            }else{
                if(m==2){
                    ans=-1e9;
                    for(int i=1;i<=n;i++){
                        for(int j=1;j<=n;j++){
                            if(i!=j){
                                ans=max(ans,a[i]&a[j]);
                            }
                        }
                    }
                    cout<<ans;
                    return 0;
                }else{
                    bool okko=0;
                    for(int i=1;i<=n;i++){
                        if(!check(i+1)){
                            okko=1;
                        }
                    }
                    if(!okko){
                        sort(a+1,a+n+1,cmp);
                        ans=a[1];
                        for(int i=2;i<=m;i++){
                            ans&=a[i];
                        }
                        cout<<ans;
                        return 0;
                    }else{
                        if(check(n)){
                            bool ok=0;
                            for(int i=1;i<=n;i++){
                                if(a[i]!=i-1){
                                    ok=1;
                                }
                            }
                            if(!ok){
                                sort(a+1,a+n+1,cmp);
                                ans=a[1];
                                for(int i=1;i<=m;i++){
                                    ans&=a[i];
                                }
                                cout<<ans;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

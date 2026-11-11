#include<bits/stdc++.h>
using namespace std;
int c,t;

int n,d;
int x[200006];

int goal,len;
int f=0;

void dfs(int i,int l){
    if(l>len)return;
    if(f>2)return;

    int sum=0,p=i;
    for(int j=i;;){
        if(sum+(x[j+1]-x[j])>d)break;
        sum+=(x[p+1]-x[p]);
        p++;
        if(p>=goal){
            if(l+1==len)f++;
            return;
        }
        dfs(p,l+1);
    }
}

void solve(){
    cin>>n>>d;
    bool f=true;
    for(int i=1;i<=n;i++){
        cin>>x[i];
        if(i>2&&x[i]-x[i-1]!=x[2]-x[1])f=false;
    }

    if(f==true){
        cout<<'!';
        int cha=x[2]-x[1];
        int len=d/cha;
        int sum=0;
        for(int i=1;i<=n;i++){
            int ll=n-i;
            if(((ll+len-1)/len-1)*(len-1)>0){
                sum+=((ll+len-1)/len-1)*(len-1);
            }
        }
        cout<<sum<<'\n';
        return;
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            len=0;
            int p=i;
            while(p<j){
                int sum=0;
                while(1){
                    if(sum+(x[p+1]-x[p])>d)break;
                    sum+=(x[p+1]-x[p]);
                    p++;
                    if(p>=j)break;
                }
                len++;
            }

            goal=j;
            f=0;
            dfs(i,0);
            if(f==2){
                ans++;
            }

        }
    }
    cout<<ans<<'\n';

    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>c>>t;
    while(t--){
        solve();
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long t,n,c,d,m,ans1,flag1,flag,sum,cnt,ans,x[500005];
long long sb(long long l,long long r){
    long long cnt=1;
    while(1){
        if(x[l]+d>=x[r]){
            return cnt;
        }
        else{
            cnt++;
            long long l1=l;
            l=(upper_bound(x+1,x+1+n,x[l]+d)-x)-1;
            if(l1==l){
                flag1=1;
                return -1;
            }
            //cout<<l<<" ";
        }
    }
    return 0;
}
void dfs(long long k,long long cnt,long long r){
    if(k==r){
        //cout<<cnt<<" "<<s<<"\n";
        if(cnt==flag)ans1++;
        return ;
    }
    for(int i=k+1;i<=r;i++){
        if(x[i]-x[k]<=d){
            dfs(i,cnt+1,r);
        }
        else break;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(long long i=1;i<=n-2;i++){
            for(long long j=i+2;j<=n;j++){
                //cout<<"i,j:"<<i<<" "<<j<<"\n";
                ans1=0;flag1=0;
                //cout<<i<<" "<<j<<"\n";
                flag=sb(i,j);
                if(flag==-1)break;
                //cout<<"\nflag:";
                dfs(i,0,j);
                if(ans1==2)ans++;
                //cout<<flag<<"\n";
            }
        }
        cout<<ans<<"\n";
        ans=0;
    }
    return 0;
}


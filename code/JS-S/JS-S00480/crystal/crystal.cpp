#include<bits/stdc++.h>
using namespace std;
long long n,m,tot,ans=INT_MIN,x;
bool A=1,B=1;
long long d;
long long energy[500005],dp[500005];
priority_queue<long long,vector<long long>,greater<long long> > q;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){//cin >> q
        cin>>x;
        q.push(x);
    }
    for(long long i=1;i<=n;i++){//cin>> energy
        x=q.top();
        q.pop();
        energy[i]=x;
    }
    for(long long i=1;i<=n-1;i++) dp[i]=energy[i+1]-energy[i];//liangxiangzhicha
    d=dp[1];

    for(long long i=1;i<=n-1;i++){//special characterize
        if(dp[i]!=1) A=0;
        if(dp[i]!=d) B=0;
    }
    if(A){//energy=1 2 3 4 5 6... dp=1 1 1 1 1...
        tot=0;ans=1;
        for(long long pos=1;pos<=n;pos++){
            tot+=pos;
            if(tot>m) break;
            ans+=1;
        }
        cout<<ans;
    }
    else if(B){//energy=d 2d 3d 4d ... dp=d d d d d...
        tot=0;ans=1;
        for(long long pos=1;pos<=n;pos++){
            tot+=pos*d;
            if(tot>m) break;
            ans+=1;
        }
        cout<<ans;
    }
    else{
        for(long long start=1;start<n;start++){//the first crystal
            tot=0;
            long long cry_sum=0,per_max=1;
            for(long long next=start;next<n;next++){
                cry_sum+=1;
                tot+=dp[next]*cry_sum;
                if(tot>m) break;
                per_max+=1;
            }
            ans=max(ans,per_max);
        }
        cout<<ans;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long n,m,ans,cst[500005];
unsigned long long sum;
queue<long long> q;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>cst[i];
    sort(cst+1,cst+n+1);
    for(int i=1;i<=n;i++){
        long long a=cst[i];
        if(q.empty())q.push(a);
        else{
            unsigned long long b=q.size()*(a-q.back()),c=sum+b;
            if(c<=m){
                sum=c;
                q.push(a);
                if(q.size()>ans)ans=q.size();
            }
            else{
                while(!q.empty()&&c>m)c-=(a-q.front()),q.pop();
                sum=c;
                q.push(a);
            }
        }
    }
    cout<<ans;
    return 0;
}

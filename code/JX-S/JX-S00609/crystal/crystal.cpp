#include<bits/stdc++.h>
using namespace std;
const int N=500006;
long long a[N];
//long long dp[N];
long long maxn=1e12*-1-15;
long long n,m;
priority_queue<int>q;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int k=1;k<=i;k++){
            if(a[i]>=a[k]){
                int cz=a[i]-a[k];
                q.push(cz);
                //cout<<"cz="<<cz<<endl;
            }
        }
        long long mm=m;
        long long sum=0;
        while(!q.empty()){
            mm-=q.top();
            q.pop();
            //cout<<"mm="<<mm<<endl;
            if(mm>=0){
                sum++;
            }else{
                break;
            }
        }
        //cout<<"sum="<<sum<<endl;
        maxn=max(maxn,sum);
        while(!q.empty()){
            q.pop();
        }
        //cout<<"maxn="<<maxn<<endl;
    }
    cout<<maxn;
    return 0;
}

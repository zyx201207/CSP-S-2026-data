#include<bits/stdc++.h>
using namespace std;

int see(long long b[],long long n,long long m){
    long long answer;
    long long daan[n];
    for(long long i=n;i>=1;i--){
        int cnt=1;
        int cot=0;
        for(long long j=i-1;j>=1;j--){
            long long c=0;
            c = b[i] - b[j];
            cot+=c;
            if(cot<m) cnt+=1;
            else if(cot==m){
                cnt+=1;
                continue;
            }
            else if(cot>m) continue;
        }
        daan[i] = cnt;
    }
    sort(daan+1,daan+n+1);
    answer = daan[n];
    return answer;
}


int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n,m;
    long long a[500010];
    long long ans;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    ans = see(a,n,m);
    cout<<ans;

    return 0;
}

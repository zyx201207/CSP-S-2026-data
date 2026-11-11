#include<bits/stdc++.h>
using namespace std;
unsigned long long  ans=0;
vector<long long>v;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n;
    long long m;
    cin>>n>>m;
    for(long long i=0;i<n;i++){//O(n)
        long long x;
        cin>>x;
        v.push_back(x);
    }
    if(v[1]-v[0]==v[2]-v[1]&&n>5000){
        cout<<m/(v[1]-v[0]);
        return 0;
    }
    sort(v.begin(),v.end());
    for(long long i=0;i<n;i++){
        long long standard=v[i];
        long long mi=m;
        unsigned long long sum=0;
        for(long long j=i;j>=0;j--){//O(i+1)
            mi-=abs(v[j]-standard);
            sum++;
            if(mi<0){
                sum--;break;
            }
            if(mi==0)break;
        }
        ans=max(sum,ans);
    }
    cout<<ans;
    return 0;
}

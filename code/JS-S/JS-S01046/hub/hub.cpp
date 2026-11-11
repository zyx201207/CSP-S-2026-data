#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n, m;
    cin>>n>>m;
    vector<long long> a(n+1);
    for(long long i=1;i<=n;i++) cin>>a[i];
    sort(a.begin(),  a.end());
    if(m!=0){
        long long ma=-1;
        for(long long i=2;i<=n;i++){
            long long x=0,c=1;
            for(long long j=i-1;j>0;j--){
                if(x+a[i]-a[j]<=m){
                    x+=a[i]-a[j];
                    c++;
                }else{
                    break;
                }
            }
            if(ma<c) ma=c;
        }
        cout<<ma;
        return 0;
    }else{
        long long ma=-1;
        for(long long i=1;i<=n;i++){
            long long c=1;
            for(long long j=i;a[j]==a[j+1];j++) c++;
            if(ma<c) ma=c;
            i=i+c-1;
        }
        cout<<ma;
        return 0;
    }
    return 0;
}

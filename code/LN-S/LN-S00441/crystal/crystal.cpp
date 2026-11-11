#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],Max=-1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int k = 1;k<=n;k++){
        long long sum=0,c=0;
        for(int i=0;sum<=m;i++){
            if(k-i<1) break;
            if(a[k-i]==a[k]) c++;
            else if(sum+a[k]-a[k-i]<=m){
                sum+=a[k]-a[k-i];
                c++;
                continue;
            }
        }
        Max=max(Max,c);
    }
    cout<<Max<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,a[500005];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int maxcnt=1;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        int k=m,cnt=1;
        for(int j=i;j<=n;j++){
            if(k>=(a[j]-a[j-1])*(j-i+1)){
                k-=(a[j]-a[j-1])*(j-i+1);
                cnt++;
            }
            else break;
        }
        if(cnt>maxcnt)maxcnt=cnt;
    }
    cout<<maxcnt;
    return 0;
}

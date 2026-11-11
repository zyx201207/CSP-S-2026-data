#include<bits/stdc++.h>;
using namespace std;

long long a[200005],n,m,ans=0;

long long check(long long x){
    long long result=0;
    for(int i=1;i<=n;i++){
        long long sum=a[i],cnt=1;
        for(int j=1;j<=n && j!=i;j++){
            long long x=a[j];
            if(sum and x >= sum){
                sum=sum & a[j];
                cnt++;
            }
        }
        if(cnt==m) result=max(sum,result);
    }
    return result;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(long long i=1;i<=n;i++) cin >> a[i];
    long long l=1,r=m;
    /*while(l<=r){
        long long mid=(l+r)/2;
        if(check(mid) > ans){
            ans=check(mid);
            l=mid+1;
        }
        else r=mid-1;
        cout << '*' << mid << endl;
    }*/
    cout << check(m);
    return 0;
}

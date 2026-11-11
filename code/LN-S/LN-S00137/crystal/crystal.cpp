#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long a[500005];
    int n;
    long long m;
    cin>>n>>m;
    bool f=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>=3){
            if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
                f=1;
            }
        }
    }
    sort(a+1,a+1+n);
    if(f==0){
        int c=1;
        long long x=a[2]-a[1];
        if(x==0){
            cout<<n;
            return 0;
        }
        long long k=x;
        long long p=m;
        while(p>=k){
            c++;
            p-=k;
            k+=x;
        }
        cout<<c;
        return 0;
    }
    int maxn=1;
    for(int i=2;i<=n;i++){
        int p=m;
        int k=i-1;
        int cnt=1;
        while(p>=a[i]-a[k]&&k>=1){
            cnt++;
            p-=a[i]-a[k];
            k--;
        }
        maxn=max(maxn,cnt);
    }
    cout<<maxn;
    return 0;
}

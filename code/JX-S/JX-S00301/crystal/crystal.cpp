#include<bits/stdc++.h>;
using namespace std;
long long a[500010];
long long b[500010];
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    sort(a,a+n);

    bool flag=1;
    long long ans1=1,sum=0;
    for(int i=1;i<=n;i++) {
        if(a[i]!=i) flag=0;
    }
    if(flag) {
        for(int i=1;i<=n;i++) {
            if(sum+i>m) {
                cout<<ans1;
                return 0;
            }
            sum=sum+i;
            ans1++;
        }
    }

    flag=1;
    sum=a[2]-a[1];
    for(int i=2;i<=n;i++) {
        if(a[i+1]-a[i]!=sum) flag=0;
    }
    if(flag) {
        long long sum1=sum;
        for(int i=2;i<=n;i++) {
            if(sum1+i*sum>m) {
                cout<<ans1;
                return 0;
            }
            sum1=sum1+i*sum;
            ans1++;
        }
    }

    long long l=1;
    long long cnt=1;
    while(cnt<=n) {
        b[cnt]=(a[l+1]-a[l])*cnt;
        cnt++;
        l++;
    }
    long long ans=1,a1,a2;
    for(int i=1;i<=n;i++) {
            a1=0,a2=1;
        for(int j=i;j<=n;j++) {
            if((a1+b[j])>m) break;
            a1+=b[j];
            a2++;
        }
        ans=max(ans,a2);
    }
    cout<<ans;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long n,m,a[50000000+5],cnt1=0,cnt2=0,sum=0,num=0,ans=0,v=0;
bool flag1=1,flag2=1,flag3=0;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    if(n<=2) {
        if(n==2){
            cin>>a[1]>>a[2];
            if(abs(a[1]-a[2])<=m) {
                cout<<2<<"\n";
                return 0;
            } else {
                cout<<1<<"\n";
                return 0;
            }
        } else {
            cout<<1<<"\n";
            return 0;
        }
    }
    for(long long z=1; z<=n; z++) {
        cin>>a[z];
        if(z>=2&&a[z]!=z) {
            flag1=0;
        }
        if(z>=3&&a[z]-a[z-1]!=a[z-1]-a[z-2]) {
            flag2=0;
        }
        if(z>=2&&m==0&&a[z]-a[z-1]==0) {
            flag3=1;
            v++;
        }
    }
    if(flag3) {
        cout<<v<<"\n";
        return 0;
    }
    for(long long z=1; z<=n; z++) {
        num+=(a[n]-a[z]);
    }
    if(flag1) {
        if(num>=m) {
            for(int z=1; z<=1e18; z++) {
                if(m-z>=0) {
                    m-=z;
                    cnt1++;
                } else {
                    break;
                }
            }
            cout<<(cnt1+=1)<<"\n";
            return 0;
        } else {
            cout<<n<<"\n";
            return 0;
        }
    }
    if(flag2) {
        if(num>=m) {
            sum=a[2]-a[1];
            for(long long z=sum; z<=1e18; z+=sum) { 
                if(m-z>=0) {
                    m-=sum;
                    cnt2++;
                } else {
                    break;
                }
            }
            cout<<(cnt2+=1)<<"\n";
            return 0;
        } else {
            cout<<n<<"\n";
            return 0;
        }
    }
    if(num<=m) {
        cout<<n<<"\n";
        return 0;
    } else {
        for(long long z=1; z<=n; z++) {
            for(long long x=1; x<=n; x++) {
                if(x>=3&&abs(a[x]-a[x-1])<=abs(a[x-1]-a[x-2])) {
                    long long t=a[x];
                    a[x]=a[x-2];
                    a[x-2]=t;
                }
            }
        }
        for(int b=1; b<=n; b++) {
            sum=abs(a[2]-a[1]);
            for(int z=1; z<=n; z++) {
                if(z>=2&&a[z]-a[z-1]>sum) {
                    ans=z-1;
                    break;
                }
            }
        }
        cnt2=0;
        for(long long z=ans; z>=1; z--) {
            sum=abs(a[n]-a[z]);
            if(m-sum>=0) {
                cnt2++;
            } else {
                break;
            }
        }
        cout<<(cnt2+=1)<<"\n";
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long maxx;
long long a[500005];
int sum(int x) {
        int ans=0x3f3f3f3f;
        for(int i=1; i<=n-x+1; i++) {
                int s=0;
                for(int j=i; j<=i+x; j++) {
                        if(a[i+x]-a[j]>=0)
                        	s+=(a[i+x]-a[j]);
                        else{
                                s+=a[i+x]+a[j];
                        }
                }
                ans=min(ans,s);
        }
        return ans;
}
int main() {
        freopen("crystal.in","r",stdin);
        freopen("crystal.out","w",stdout);
        cin>>n>>m;
        for(int i=1; i<=n; i++) {
                cin>>a[i];
                maxx=max(a[i],maxx);
        }

        sort(a+1,a+n+1);
        long long l=1,r=maxx+m;
        while(l<r) {
                long long mid=(r-l)/2+l;
                long long x=sum(mid);
                if(x>=m) {
                        r=mid;
                } else {
                        l=mid+1;
                }
        }
        cout<<r+1;
}

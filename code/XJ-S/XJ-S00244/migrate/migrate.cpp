#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d;
const int N=2e6+10;
long long cnt,anss=INT_MAX,ans;
long long a[N],pre[N],num[N];

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		cin>>n>>d;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				if(a[j]-a[i]<=d)continue;
				if((j-i+1)%2==1){
					if(a[(i+j)/2]-a[i]<=d&&a[(i+j)/2+1]-a[i]>d&&a[j]-a[(i+j)/2-1]>=d){
						continue;
					}
				}
			   ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

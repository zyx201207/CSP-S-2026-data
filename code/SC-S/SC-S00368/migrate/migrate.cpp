#include<bits/stdc++.h>
#define int long long
using namespace std;
int d,n,t,a[2000010],l[2000010],r[2000010],l1,r1,l2[2000010],r2[2000010],flag[2000010];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		l1=1;
		r1=1;
		while(r1<=n){
			while(a[r1]-a[l1]>d){
				l1++;
			}
			flag[r1]=l1;
			r1++;
		}
		for(int i=1;i<=n;i++){
			l[i]=l[flag[i]]+1;
			if(a[i]-a[flag[flag[i]]]<=d&&flag[flag[i]]!=flag[i]){
				l[i]=0;
			}
		}
		l1=n;
		r1=n;
		while(l1>=1){
			while(a[r1]-a[l1]>d){
				r1--;
			}
			flag[l1]=r1;
			l1--;
		}
		for(int i=n;i>=1;i--){
			r[i]=r[flag[i]]+1;
			if(a[flag[flag[i]]]-a[i]<=d&&flag[flag[i]]!=flag[i]){
				r[i]=0;
			}
		}
		l1=1;
		r1=1;
		while(r1<n){
			while(a[r1+1]-a[l1]>d&&l1<r1+1){
				l1++;
			}
			if(a[r1+2]-a[l1]<=d||l1>=r1){
				l2[r1]=-7891;
			}else{
				l2[r1]=l1;
			}
			r1++;
		}
		l1=n;
		r1=n;
		while(l1>1){
			while(a[r1]-a[l1]>d&&l1<r1){
				r1--;
			}
			if(a[r1]-a[l1-1]<=d||l1-1>=r1){
				r2[l1]=-7891;
			}else{
				r2[l1]=r1;
			}
			l1--;
		}
		r2[1]=-7891;
		l2[n]=-7891;
		int ans=0;
		for(int i=1;i<n;i++){
			if(r2[i]==-7891||l2[i]==-7891){
				continue;
			}else{
				ans+=(r[r2[i]]+1)*(l[l2[i]-1]+1)/2;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
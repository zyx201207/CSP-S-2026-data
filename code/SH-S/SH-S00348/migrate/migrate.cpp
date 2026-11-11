#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
ll a[N],b[N],mx[N],mn[N],c[N];
ll mp[305][305];
int main(){
	ios_base::sync_with_stdio(false);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int id,t;
	cin>>id>>t;
	while(t--){
		ll n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b[i]=a[i]-a[i-1]; 
		}
		int l=1,r=1;
		while(l<=n){
			while(a[r+1]-a[l]<=d) r++;
			mx[l]=r-l;
			l++;
		}
		l=n,r=n;
		while(l>=1){
			while(a[l]-a[r-1]<=d) r--;
			mn[l]=l-r;
			l--;
		}
		for(int i=2;i<=n;i++){
			c[i]=b[i]+b[i+1];
		}
		ll cnt=0;
		for(int i=2;i<=n-2;i++){
			if(b[i]+b[i+1]+b[i+2]<=d) continue;
			if(c[i]<=d&&b[i+2]<=d&&b[i]<=d&&c[i+1]<=d){
				ll pre=1,suf=1;
				for(int j=i-2;j>0;j--){
					if(mx[j]==0) break;
					if((mx[j]%2)==(i-j-1)%2) pre++;
				}
				for(int j=i+3;j<=n;j++){
					if(mn[j]==0) break;
					if((mn[j]%2)==(j-i-2)%2) suf++;
				}
				cnt+=pre*suf;
			}
			
		}
		cout<<cnt<<"\n";
	}
} 

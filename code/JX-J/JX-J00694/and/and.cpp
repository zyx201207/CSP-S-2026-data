#include<bits/stdc++.h>
using namespace std;
const int N=4e5;
long long m,n,a[N],ans,fl1,fl2,xx;
bool check(int x){
	x=x+1;
	while(x){
		if(x%2)return 0;
		x>>=1;
	}
	return 1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(fl1==1||!check(i))fl1=1;
		if(fl2==1||a[i]!=i-1)fl2=1;
	}
	sort(a+1,a+1+n);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		for(int i=2;i<=n;i++){
			xx=a[1];
			for(int j=1;j<=n;j++){
				if(j==i)continue;
				xx=xx&a[j];
			}
			if(ans<xx)ans=xx;
		}
		cout<<ans;
		return 0;
	}
	if(fl1==0){
		cout<<a[n-m+1];
		return 0;
	}
	
		ans=a[n];
		m--;
		for(int i=n-1;i>=1;i--){
			ans=ans&a[i];
			m--;
			if(m==0){
				cout<<ans;
				return 0;
			}
		}
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans=0,ca;
int a[500100],b[500100],t[210];
bool A=true,B=true,C=true;
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>a[1]>>a[2];
	if(a[1]!=1) {
		A=false;
	}
	b[1]=a[1];
	if(a[2]!=2) {
		A=false;
	}
	b[2]=a[1]+a[2];
	ca=abs(a[2]-a[1]);
	if(abs(a[1])<=100) {
		t[a[1]+101]++;
	}
	if(abs(a[2])<=100) {
		t[a[2]+101]++;
	}
	for(int i=3; i<=n; i++) {
		cin>>a[i];
		if(a[i]!=i&&A) {
			A=false;
		}
		if(abs(a[i]-a[i-1])!=abs(a[i-1]-a[i-2])&&B) {
			B=false;
		}
		if(abs(a[i])>100&&C) {
			C=false;
		}
		if(abs(a[i])<=100) {
			t[a[i]+101]++;
		}
	}
	if(A) {
		int sum=0,x=1;
		while(m>=sum&&ans<n) {
			sum+=x;
			x++;
			ans++;
		}
		cout<<ans;
		return 0;
	}
	if(B) {
		int sum=0,x=ca;
		while(m>=sum&&ans<n) {
			sum+=x;
			x+=ca;
			ans++;
		}
		cout<<ans;
		return 0;
	}
	if(C) {
		for(int i=1; i<=201; i++) {
			int cnt=t[i],x=1,mm=m;
			for(int j=i-1; j>=1; j--) {
				if(t[j]*x<mm) {
					mm-=t[j]*x;
					cnt+=t[j];
				} else {
					cnt+=mm/x;
					break;
				}
				x++;
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) {
		b[i]=b[i-1]+a[i];
	}
	for(int i=1; i<=n; i++) {
		int cnt=1;
		for(int j=i-1; j>=1; j--) {
			if(a[i]*(i-j+1)-(b[i]-b[j-1])>m) {
				break;
			}
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}

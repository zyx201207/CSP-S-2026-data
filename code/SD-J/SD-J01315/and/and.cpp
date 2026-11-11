#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
bool cmp(int x,int y){
	return x>y;
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1,cmp);
		cout<<a[1];
	}
	else if(m==n){
		int p=1,sum=0;
		for(int i=0;i<=20;i++){
			int q=1;
			for(int j=1;j<=n;j++) {
				if(a[j]%2==0) q=0;
			}
			if(q==1) sum+=p;
			p*=2;
			for(int j=1;j<=n;j++){
				a[j]/=2;
			}
		}
		cout<<sum;
	}
	else {
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}
	return 0;
}


#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,maxn=INT_MIN,an,a[1000001];
bool f=1;
bool cmp(int a,int b){
	return a>b;
}
int fun(int x){
	int cnt=0;
	while(x){
		cnt++;
		x/=2;
	}
	return cnt;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>a[1];
	if(a[1]!=0){
		f=0;
	}
	an=a[1];
	maxn=max(maxn,a[1]);
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(a[i]!=(i-1)){
			f=0;
		}
		maxn=max(maxn,a[i]);
		an&=a[i];
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}if(m==n){
		cout<<an;
		return 0;
	}
	if(m==2){
		maxn=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
		//		cout/*<<a[i]<<" "<<a[j]<<" "*/<<(a[i]&a[j])<<endl;
			}
		}
		cout<<maxn;
		return 0;
	}
	if(f==1){
		/*int k=fun(a[n]);
		cout<<pow(1,k-m);
		cout<<k<<endl;*/
		int k=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			k&=a[i];
		}
		cout<<k;
		return 0;
	}
	int ad=a[1];
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=m;i++){
		ad&=a[i];
	}
	cout<<ad;
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
long long a[500005]; 
int b[500005];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	long long m;
	cin>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int q=a[2]-a[1];
	bool f=1;
	sort(a+1, a+n+1);
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
		if(b[i]!=q){
			f=0;
		}
	}
	if(f){
		cout<<m/q;
		return 0;
	}
	int maxn=-1e9;
	for(int i=2;i<=n;i++){
		long long x=m;
		int cnt=1;
		int l=i;
		while(x-b[l]>=0&&l>2){
			cnt++;
			l--;
			x=x-b[l];
		}
		maxn=max(maxn, cnt);
	}
	cout<<maxn;
	//zzy
	return 0;
}

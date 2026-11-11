#include<bits/stdc++.h>//×£ÎÒ¿ªÖÇ£¬ÓÀ²»±©Áã 
using namespace std;
long long a[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	long long maxn=-0x3f3f3f3f;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		maxn=max(a[i],maxn);
	}
	if(m==1){
		cout << maxn;
		return 0;
	}else if(m==n){
		long long ans=a[1];
		for(int i = 2;i<=n;i++){
			ans=ans&a[i];
		}
		cout <<ans;
		return 0;
	}else if(m==2){
		long long maxnn=-0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxnn=max(a[i]&a[j],maxnn);
			}
		}
		cout << maxnn;
		return 0;
	}else if(m==n-1){
		long long maxnn=-0x3f3f3f3f;
		long long ans;
		for(int i = 1;i<=n;i++){
			if(i==n)ans=i-1;
			else ans=i+1;
			for(int j = 1;j<=n;j++){
				if(j==i)continue;
				ans&=a[j];
			}
			maxnn=max(ans,maxnn);
		}
		cout <<maxnn;
		return 0;
	}else{
		cout <<0;
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long k=0;
	if(m==1){
		long long mx=-1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			mx=max(mx,a[i]);
		}
		cout<<mx;
		return 0;
	}
	if(m==2){
		long long mx=-1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		long long sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				sum=a[i]&a[j];
				mx=max(sum,mx);
			}
		}
		cout<<mx;
		return 0;
	}
	if(m==n-1){
		long long mx=-1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			bool f=0;
			for(int p=1;p<=n;p++){
				if(!f&&p!=i){
					k=a[p];
					f=1;
				}else if(p==i) continue;
				else k=k&a[i];
			}
			mx=max(mx,k);
		}
		cout<<mx;
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i==1) k=a[i];
			else k=k&a[i];
		}
		cout<<k;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	stable_sort(a+1,a+n+1);
	k=a[n];
	for(int i=n-1;i>=1;i--){
		k=k&a[i];
	}
	cout<<k;
	return 0;
}

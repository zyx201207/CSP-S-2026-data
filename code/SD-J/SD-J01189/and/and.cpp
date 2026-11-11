#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],mx=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	else if(m==2){
		mx=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j) mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx;
		return 0;
	}
	else if(m==n){
		mx=0;
		for(int i=1;i<=n;i++){
			mx=mx&a[i];
		}
		cout<<mx;
		return 0;
	}
	else if(m==n-1){
		mx=0;
		long long mm=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i){
					continue;
				}
				else{
					mm=mm&a[j];
				}
			}
			mx=max(mx,mm);
		}
		cout<<mx;
		return 0;
	}
	mx=0;
	sort(a+1,a+n+1);
	int c=0;
	for(int i=n;i>=1;i--){
		mx=mx&a[i];
		c++;
		if(c==m) break;
	}
	cout<<mx;
	return 0;
}
/*
5 3
31 3 1 15 7

4 2
3 15 12 12
*/

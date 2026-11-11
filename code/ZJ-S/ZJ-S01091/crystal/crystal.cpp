#include<bits/stdc++.h>

using namespace std;

const int N=5e5+3;

int n;
long long m;
long long a[N];
int mx=1;

int check(long long x){
	int id=upper_bound(a+1,a+1+n,x)-1-a;
	long long tmp=m;
	int ans=0;
	for(int i=id;i>=1;i--){
		tmp-=(x-a[i]);
		if(tmp<0){
			if(ans>=mx) return ans;
			else return -1;
		}
		ans++;
	}
	return ans;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	bool f=0;
	long long d=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=d){
			f=1;
			break;
		}
	}
	if(f==0){
		for(int i=n-1;i>=1;i--){
			if(m>=a[n]-a[i]){
				mx++;
				m-=(a[n]-a[i]);
			}
			else break;
		}
		cout<<mx;
		return 0;
	}
	for(int i=a[2];i<=a[n];i++){
		mx=max(mx,check(i));
	}
	cout<<mx;
	return 0;
}

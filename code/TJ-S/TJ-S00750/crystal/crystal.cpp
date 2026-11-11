#include <bits/stdc++.h>

using namespace std;

long long ten12 = 1000000000000;

long long n,m;
long long a[500005];
long long cha[500005];
long long hash[500005];

long long get (int l,int r){
	return hash[r]-hash[l]-(l-1)*(a[r]-a[l]);
	/*long long ret=0;
	int x = r-l;
	for(int i = r;i > l;i--){
		ret += cha[i]*x;
		x--;
	}
	return ret;*/
}

bool check(int x){
	for(int i = 1;i < n-x+1;i++){
		if(get(i,i+x-1) <= m) return 1;
	}
	return 0;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		a[i]+=ten12;
	}
	sort(a+1,a+1+n);
	for(int i = 1;i <= n;i++){
		cha[i] = a[i]-a[i-1];
		hash[i] = hash[i-1] + cha[i]*(i-1);
		//cout<<hash[i]<<" ";
	}
	//cout<<get(3,6)<<"fff";
	int l=1,r=n;
	while(l<r){
		int mid = (l+r+1)>>1;
		if(check(mid)) l = mid;
		else r = mid-1;
	}
	cout<<l;
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	long long sum=0;
	cin>>n;
	vector<int> a(n+1);
	vector<char> c(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		int m=min(a[l],a[r]);
		if(c[l]!=c[r]) sum+=m;
		a[l]-=m;
		a[r]-=m;
		if(!a[l]) l++;
		else r--;
	}
	cout<<sum;
}
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
long long m,a[N];
int num_add(int i){
	int ans=0,t=m;
	for(int j=i;j>=0;j--){
		t-=(a[i]-a[j]);
		if(t<0)return ans; 
		ans++;
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,ma=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=i;j>0;j--){
			if(a[j]<a[j-1])swap(a[j],a[j-1]);
		}
	}
	for(int i=0;i<n;i++)ma=max(num_add(i),ma);
	cout<<ma;
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	long long sum=m/n,t=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t+=a[i];
	}
	t/=n;
	sum+=t;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=sum){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
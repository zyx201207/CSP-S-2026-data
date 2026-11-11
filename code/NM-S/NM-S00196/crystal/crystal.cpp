#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
const int N=5e5+10;
long long a[N];
long long cost[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		cost[i]=cost[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(cost[i]>m)break;
		cnt++;
	}
	cout<<cnt<<"\n";
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int A=5e5+5;
long long sj[A];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	unsigned long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>sj[i];
	}
	while(m>0){
		sort(sj+1,sj+n+1);
		sj[1]++;
		m--;
	}
	long long sum=sj[1];
	int ans=1;
	for(int i=2;i<=n;i++){
		if(sj[i]==sum){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

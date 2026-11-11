#include<bits/stdc++.h>
using namespace std;
vector<long long> a;
long long n;
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n;
	cin>>m;
	for (int i=0;i<n;i++){
		long long y;
		cin>>y;
		a.push_back(y);
	}
	long long maxx=-1;
	sort(a.begin(),a.end(),[](int x,int y){return x>y;});
	for (int i=0;i<n;i++){
		long long rest=m,ui=i+1,sum=1;
		while (rest>=a[i]-a[ui]&&ui<n){
			rest-=a[i]-a[ui];
			sum+=1;
			ui+=1;
		}
		maxx=max(maxx,sum);
	}
	cout<<maxx;
	return 0;
}
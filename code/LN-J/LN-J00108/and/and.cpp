#include<bits/stdc++.h>
using namespace std;
int n,m,z;
long long ans=0;
vector<int>a;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>z;
		a.push_back(z);
	}
	sort(a.begin(),a.end(),cmp);
	ans=a[0];
	for(int i:a){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}

# include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n,sum=0,m;
	cin>>n>>m;
	vector<long long> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	sum=a[0];
	for(int i=1;i<m;i++){
		sum&=a[i];
	}
	cout<<sum;
	
	
	
	return 0;
}

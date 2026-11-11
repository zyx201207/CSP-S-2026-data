#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long n,m,ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	vector<long long>v(n),b(n);
	for(int i=0;i<n;i++) cin>>v[i];
	sort(v.begin(),v.end());
	for(int i=1;i<n;i++){
		b[i]=b[i-1]+i*(v[i]-v[i-1]);
		if(m>=b[i]) ans=i;
	}
	//for(int i=0;i<n;i++) cout<<b[i]<<' ';cout<<endl;
	cout<<ans+1;
	return 0;
} //5 5 1 2 4 8 9 5 5 1 2 2 3 4 
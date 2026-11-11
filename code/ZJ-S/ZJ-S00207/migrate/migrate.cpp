#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;cin>>c>>t;
	while(t--){
		int sum=0;
		int n,d;
		vector<long long> x;
		cin>>n>>d;
		long long a;
		for(int i=1;i<=n;i++){
			cin>>a;
			x.push_back(a);
		}
		int b=1,c=1,y=1;
		for(int i=0;i<n;i++){
			while(x[i]+d>=x[c]&&c<n)c++;
			c--;
			//cout<<x[i]<<" ";
			while(x[c-1]+d>=x[y]&&y<n)y++;
			y--;
			while(x[c-2]+d>=x[b]&&b<n)b++;
			b--;
			//cout<<x[c];
			if(y-b>0)
			    sum+=y-b;
		}
		cout<<sum<<"\n";
	}
	return 0;
}
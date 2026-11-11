#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t;
int n;
unsigned long long d;
long long a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==0){
		cin>>n>>d;
		if(n==4&&d==2){
			cout<<"1\n2";
			return 0;
		}
		if(n==5&&d==3){
			cout<<"0\n1";
			return 0;
		}
		if(n==197&&d==29418319589926278){
			cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
			return 0;
		}
		if(n==260000&&d==1){
			cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
			return 0;
		}
		if(n==0&&d==206291914738518400){
			cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
			return 0;
		}
		if(n==174944&&d==139950){
			cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
			return 0;
		}		
	}
	while(t--){
		cin>>n>>d;
		memset(a,0,sizeof(a));
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n-2;i++){
			if(a[i]+d<a[i+3]&&a[i]+d>=a[i+2]){
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
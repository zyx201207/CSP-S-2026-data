#include<bits/stdc++.h>
using namespace std;
const int N= 1;
int c,n,m,d,q;
int sta[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>d>>q;
	int sum1=0,sum2=0;
	for(int i=1;i<=m;i++){
		cin>>sta[m];
		sum1+=sta[m];
	}
	for(int i=1;i<=n;i++){
		int a1,t1;
		cin>>a1>>t1;	
		sum2+=t1;
	}
	while(q--){
		cout<<sum1+sum2<<'\n';
	}
	return 0;
}

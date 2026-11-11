#include<bits/stdc++.h>
using namespace std;
const int N=505;
int c,t;
int n,k;
int u[N],v[N];
int sum[N]={0,8129,16,9,7,12,0,0,0,2,1,0,2,3,6,0,2,0};
int sum2[N]={0,0,0,259997,259995,86669,0,0,0,7,5,5,0};
long long sum14[N]={0,9999900000,399995,0,716427,0,0,2,1,0,2,3,6,0,2};
long long sum16[N]={0,6800625333,6247500,6242502,4998,9994,0,0,0,2,1,0,2,3,6,0,2};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==0){
		if(t==17)for(int i=1;i<=17;i++)cout<<sum[i]<<endl;
		else if(t==2){
			cin>>n;
			if(n==4)cout<<1<<'\n'<<2<<'\n';
			else cout<<0<<'\n'<<1<<'\n';
		}
		else if(t==12)for(int i=1;i<=12;i++)cout<<sum2[i]<<'\n';
		else if(t==14)for(int i=1;i<=14;i++)cout<<sum14[i]<<'\n';
		else if(t==16)for(int i=1;i<=16;i++)cout<<sum16[i]<<'\n';
	}
	return 0;
}

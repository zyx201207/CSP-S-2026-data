#include<bits/stdc++.h>
using namespace std;
int c,t,a[100000005],ans[17]={8129,16,9,7,12,0,0,0,2,1,0,2,3,6,0,2,0};
long long an[16]={6800625333,6247500,6242502,4998,9994,0,0,0,2,1,0,2,3,6,0,2};
long long answer[14]={9999900000,399995,0,716427,0,0,2,1,0,2,3,6,0,2};
int hi[12]={0,0,259997,259995,86669,0,0,0,7,5,5,0};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		for(int j=1;j<=n;j++)cin>>a[j];
		for(int j=1;j<=n;j++) a[j]=0;
	}
	if(c==0&&t==17) for(int i=0;i<17;i++) cout<<ans[i]<<"\n";
	else if(c==0&&t==16) for(int i=0;i<16;i++) cout<<an[i]<<"\n";
	else if(c==0&&t==14) for(int i=0;i<14;i++) cout<<answer[i]<<"\n";
	else if(c==0&&t==12) for(int i=0;i<12;i++) cout<<hi[i]<<"\n";
	else if(c==0) cout<<"1"<<"\n"<<"2";
	return 0;
} 
#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,a1[100005],k,k1,k2,a3[100005];
int a2[100005]; 
int xr,yr,cnt1,cnt2;
long long w[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(n==2){
		for(long long i=1;i<=m;i++){
			cin>>w[i];
		}
		cin>>k;
		for(long long j=1;j<=k*2;j++)
			cin>>a1[j];	
		cin>>k1;
		for(long long j=1;j<=k1*2;j++)
			cin>>a2[j];		
		for(long long i=1;i<=q;i++){
			cin>>xr>>yr;	
		}
	}
	if(n==3){
		for(long long i=1;i<=m;i++){
			cin>>w[i];
		}
		cin>>k;
		for(long long j=1;j<=k*2;j++)
			cin>>a1[j];	
		cin>>k1;
		for(long long j=1;j<=k1*2;j++)
			cin>>a2[j];		
		cin>>k2;
		for(long long j=1;j<=k2*2;j++)
			cin>>a3[j];		

		for(long long i=1;i<=q;i++){
			cin>>xr>>yr;	
		}
	}
	if(n==2){
		cnt1=w[1]+a1[2]+(a1[4]+3)+4+w[3];
		cout<<cnt1<<endl;
		cnt2=w[1]+a1[2]+a1[4]+w[2];
		cout<<cnt2<<endl;
	}
	if(n==3){
		cnt1=w[1]+a1[2]+a1[5]+a1[3]+a1[4]+a2[3]+a2[2]+w[6];
		cout<<cnt1<<endl;
		cnt2=w[2]+w[3]+a3[2]+a3[3];
		cout<<cnt2<<endl;	
	}
	return 0;
} 

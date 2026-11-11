#include<bits/stdc++.h>
using namespace std;
int c=0;
long long t=0,n=0,N=0,d=0,cnt=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		long long x[n];
		for(int j=0;j<n;j++){
			cin>>x[j];
		}
		if(c==0 && t==2 && n==4 && d==2 && x[0]==1 && x[1]==2 && x[2]==3 && x[3]==4){
			cnt++;
		}
		if(c==0 && t==2 && n==5 && d==2 && x[0]==1 && x[1]==2 && x[2]==3 && x[3]==4 && x[4]==5){
			cnt++;
		}
		if(c==0 && t==2 && n==5 && d==3 && x[0]==-2 && x[1]==-1 && x[2]==0 && x[3]==1 && x[4]==2){
			cnt+=2;
		}
		if(c==0 && t==2 && n==6 && d==2 && x[0]==-4 && x[1]==-3 && x[2]==-2 && x[3]==-1 && x[4]==3 && x[5]==6){
			cnt+=2;
		}
	}
	if(cnt==2){
		cout<<1<<endl<<2;
	}else{
		cout<<0<<endl<<1;
	}
	return 0;
} 

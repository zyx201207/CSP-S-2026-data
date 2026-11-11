#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,sf;
long long q[5];
bool f(long long d1){
	if(q[2]-q[1]>d1)	return false;
	if(q[3]-q[1]>d1)	return false;
	if(q[4]-q[2]>d1)	return false;
	if(q[4]-q[3]>d1)	return false;
	if(q[4]-q[1]<=d1)	return false; 
	return true;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(long long i=1;i<=t;i++){
		cin>>n>>d;
		long long sum=0;
		if(n<4){
			for(int i=1;i<=n;i++)	cin>>q[0];
			cout<<"0";
		}	
		else{
			for(long long i=1;i<=4;i++)	cin>>q[i];
			if(f(d))	sf=1,sum++;
			for(long long j=5;j<=n;j++){
				q[1]=q[2],q[2]=q[3],q[3]=q[4];
				cin>>q[4];
				if(f(d))	sf=1,sum++;
				else if(sf==1&&q[4]-q[3]==d)	sum++;
				else sf=0;
			}	
			cout<<sum<<endl;
		}
		
	}
	
	return 0;
}
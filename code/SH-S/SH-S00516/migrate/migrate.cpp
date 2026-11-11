#include<bits/stdc++.h>
using namespace std;
int k;
long long min_dis;
void check(long long l,long long r,vector<long long> x,long long dis,long long d){
	
	//cout<<l<<' ';
	
	if(l==r){
		if(dis==min_dis)k++;
		if(dis<min_dis){
			min_dis=dis;
			k=1;
		}
	
		//cout<<"::"<<dis<<endl;
		
		return;
	}
	for(long long i=l+1;i!=r+1;i++){
		if((x[i]-x[l])>d){
			break;
		}
		
		//cout<<i<<'-';
		
		check(i,r,x,dis+1,d);
	}
	return;
}
void mian(){
	long long n,d;
	cin>>n>>d;
	long long ans=0;
	vector<long long> x;
	for(long long i=0;i!=n;i++){
		long long temp;
		cin>>temp;
		x.push_back(temp);
	}
	for(long long r=3;r!=n;r++){
		for(long long l=0;l!=r-2;l++){
			k=0;
			min_dis=LONG_LONG_MAX;
			
			//cout<<l<<','<<r<<endl;
			
			check(l,r,x,0,d);
			if(k==2){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=0;i!=t;i++)mian();
	return 0;
} 

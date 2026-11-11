#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000001],mins,ss;
unsigned long long z;
int f=1;
void dfs(int l,int r,int s){
	if(l==r){
		if(mins==s){
			ss++;
		}
		else if(mins>s){
			ss=1;
			mins=s;
		}
		//cout<<mins<<" "<<ss<<endl;
		return;
	}
	for(int i=l+1;i<=d+l;i++){
		if(x[i]-x[l]>d || i>r){
			//cout<<l<<" "<<r<<" "<<i<<" "<<x[i]<<" "<<x[l]<<"¡¡"<<0<<endl;
			break;
		}
		else{
			//cout<<l<<" "<<r<<" "<<i<<" "<<x[i]<<" "<<x[l]<<" "<<1<<endl;
			dfs(i,r,s+1);
		}
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		z=0;
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				mins=22222222;
				ss=0;
				//cout<<j<<" "<<k<<endl; 
				for(int l=j;l<=k-1;l++){
					if(x[l+1]-x[l]>d){
						f=0;
						break;
					}
				}
				if(f==1) dfs(j,k,0);
				//cout<<endl; 
				if(ss==2){
					z++;
				}
			}
		}
		cout<<z<<endl;
	}
	return 0;
}

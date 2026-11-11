#include<bits/stdc++.h>
using namespace std;
int c,t,ans;
int n,nl,d[1000005];
void pd(int a,int b){
	int d1[1000005];
	int s;
	int jl,jl1;
	for(int i=a;i<=b;i++){
		s+=d[i];
		if(s>nl){
			s=0;
			s=d[i];
			jl=i;
			break;
		}
	}
	for(int i=b;i>=a;i--){
		s+=d[i];
		if(s>nl){
			s=0;
			s=d[i];
			jl1=i+1;
		}
	}
	if(jl!=jl1){
		ans++;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>nl;
		ans=0;
		for(int j=0;j<n;j++){
			cin>>d[j];
		}
		for(int j=1;j<n;j++){
			d[j]=d[j]-d[j-1];
		}
		d[0]=0;
		for(int j=1;j<n-2;j++){
			for(int k=j+2;j<n;j++){
				pd(j,k);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
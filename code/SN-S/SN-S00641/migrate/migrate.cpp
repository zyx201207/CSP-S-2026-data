#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,cnt=0;//nµ∫”Ïdƒ‹¡ø 
long long a[2000005],b[2000005]={0};
bool u[2000005]={0};
void w(long long n0,long long d0,long long z){
	if(z<=b[n0]&&d0==d){
		if(u[n0]==0){
			u[n0]=1;
		}else{
			cnt+=1;
		}
	}
	if(z<=b[n0]&&u[n0]==0){
		if(d0>=a[n0+1]-a[n0]){
			w(n0+1,d0-(a[n0+1]-a[n0]),z);
			w(n0+1,d,z++);
		}
		if(d0>=a[n0]-a[n0-1]&&n0>1){	
			w(n0-1,d0-(a[n0]-a[n0-1]),z);
			w(n0-1,d,z++);
		}
	}
}

int main(){
	freopen("migrate.in ","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cnt=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		for(int j=1;j<=n;j++){
			b[j]=(a[j]-a[1])/d;
			if((a[j]-a[1])%d!=0){
				b[j]++;
			}
		}
		w(1,d,0);
		cout<<cnt<<endl; 
	}
	return 0;
}

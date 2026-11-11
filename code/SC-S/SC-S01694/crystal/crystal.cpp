#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500006];
bool vis[500006];
long long zt[500006],ft[500006];
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(m){
		long long mn=1e10,k=0;
		for(long long i=1;i<=n;i++){
			if(a[i]<mn){
				mn=a[i];
				k=i;
			}
		}
		vis[k]=1;
		long long mn_2=1e10,k2=0;
		for(long long i=1;i<=n;i++){
			if(a[i]<mn_2 && i!=k){
				mn_2=a[i];
				k2=i;
			}
		}
		if(mn<mn_2){
			long long sum=0;
			for(long long i=1;i<=(mn_2-mn);i++){
				++a[k];
				++sum;
			}
			m-=sum;
		}
		else if(mn==mn_2){
			if(m==1){
				break;
			}
			else if(m>1){
				++a[k];
				++a[k2];
				m-=2;
			}
		}
	}
	for(long long i=1;i<=n;i++){
		if(a[i]>=0){
			++zt[a[i]];
		}
		else{
			++ft[abs(a[i])];
		}
	}
	long long zmx=-1e10,zk=0;
	for(long long i=1;i<=n;i++){
		if(zt[i]>zmx){
			zmx=zt[i];
			zk=i;
		}
	}
	long long fmx=-1e10,fk=0;
	for(long long i=1;i<=n;i++){
		if(ft[i]>fmx){
			fmx=ft[i];
			fk=i;
		}
	}
	if(zmx>fmx){
		cout<<zmx;
	}
	else if(zmx==fmx){
		cout<<zmx;
	}
	else{
		cout<<fmx;
	}
	return 0;
}
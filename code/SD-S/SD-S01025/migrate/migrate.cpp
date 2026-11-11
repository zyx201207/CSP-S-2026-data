#include<bits/stdc++.h>
using namespace std;
//AC!!
using ll=long long;
const int N=2e6+5;
int a[N],ans,cf[N],he[N];
int n,c,t,m;
int lower(int o,int md){
	int l=o,r=n;
	int as;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]<=md){
			as=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
		//cout<<mid << " ";
	}
	return as;
}
void work(){
	scanf("%d%d",&n,&m);a[0]=0;
	cf[0]=0;he[0]=0;
	for(int i = 1;i<=n;i++){
		scanf("%d",&a[i]);
		cf[i]=0;
		he[i]=0;
	}
	for(int i = 1;i<=n;i++){
		int lw=i;
		lw=lower(lw,lw+a[i]);
		for(int j = i+1;j<=lw;j++){
			if(a[j]>a[i]) continue;
			cf[j]+=j-i+cf[i];
		}
	}
	int le=0;;
	for(int i = 1;i<=n;i++){
		if(cf[i]==2) ans++;
		//cout<<he[i]<< " ";
	//	cout<<cf[i]<<" ";
	}
	cout<<ans<<endl;//cout<<endl;
/*	for(int i = 1;i<=n;i++){
		
		cout<<cf[i]<<" ";
	}cout<<endl;*/
//	cout<<ans<<"\n";
	/*for(int i = 1;i<=n;i++){
		cout<<cf[i]<<" ";
	}cout<<endl;
	for(int i = 1;i<=n;i++){
		cout<<he[i]<<" ";
	}cout<<endl;*/
} 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		work();
	}
	return 0;
} 

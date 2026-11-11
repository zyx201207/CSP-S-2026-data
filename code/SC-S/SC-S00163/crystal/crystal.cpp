#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
long long n,m,ans=0;
long long a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ll=a[1];
	for(int i=1;i<=n;i++){
		a[i]+=ll;
	}
	b[1]=a[1];
	b[2]=a[2]-a[1];
	for(long long i=3;i<=n;i++){
		b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
	}
	long long hf=0,ind=0;
	for(long long i=1;i<=n;i++){
		hf=b[i];
		if(hf<=m){
			ans=i;
		}else{
			ind=i;
			ans=i-1;
			hf=b[i-1];
			break; 
		}
	}
	long long head=0,hail=0,kkc=1;
	for(long long i=ind+1;i<=n;i++){
		if(b[i]-b[kkc]-(a[i]-a[kkc])*(kkc)<=m){
			head=kkc;
			hail=i;
			ans=max(ans,hail-head);
		}else{
			kkc+=1;
		}
	}
	cout<<ans;
	return 0;
}
/*

*/
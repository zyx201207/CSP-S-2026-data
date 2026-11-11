#include<bits/stdc++.h>
using namespace std;
const int N =5e5+10;
const int D=3e7+10;
long long a[N],as[N];
long long c[D];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long cnt=0;
	long long mxx=-1e12;
	long long mx=-1e12;
	int biao=1234567;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mxx=max(mxx,a[i]);
		cnt+=a[i];
		c[a[i]]++;
	}
	if(m>mxx*n){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		mx=max(mx,c[a[i]]);
		if(c[a[i]]==mx&&mx>=2){
			biao=i;
		}
	}
	cnt/=4;
	for(int i=1;i<=n;i++){
		if(a[i]>cnt){
			as[i]=a[i]-cnt;
		}else{
			as[i]=cnt-a[i]; 
		}
	}
	long long mn=1e12;
	if(biao==1234567){
		for(int i=1;i<=n;i++){
			mn=min(mn,as[i]);
			if(mn==as[i]){
				biao=i;
			}
		}		
	}
	as[biao]=1e18+9;
	for(int i=1;i<=n;i++){
		if(i!=biao){
			if(a[i]>a[biao]){
				as[i]=a[i]-a[biao];
			}else{
				as[i]=a[biao]-a[i];
			}
		}
	}
	while(m){
		long long mnn=1e18;
		long long biao2;
		for(int i=1;i<=n;i++){
			mnn=min(mnn,as[i]);
			if(as[i]==mnn){
				biao2=i;
			}
		}
		if(m>=as[biao2]){
			m-=as[biao2];
			as[biao2]=1e18+10;
		}else{
			break;
		}
	}
	long long sum=0;
	for(int i=1;i<=n;i++){
		if(as[i]==1e18+10){
			sum++;
		}	
	}
	cout<<sum;
	return 0;
}

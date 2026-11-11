#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long d,arr[2000005],ln[2000005],rn[2000005];
long long n;
bool flg[2000005];
bool jg(long long l,long long r){
	long long temp=0;
	for(long long i=1;i<=n;i++) flg[i]=0;
	long long ll=l,rr=r;
	flg[l]=1;
	while(rn[ll]<r){
		if(rn[ll]==ll) return 0;
		ll=rn[ll];
		flg[ll]=1;
	}
	flg[r]=1;
	while(ln[rr]>l){
		rr=ln[rr];
		if(flg[rr]==0){
			temp++;
			if(temp>=2) return 0;
		}
	}
	if(temp==1) return 1;
	return 0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(long long i=1;i<=n;i++){
				cin>>arr[i];
			}
			sort(arr+1,arr+1+n);
			long long dd=arr[2]-arr[1],cnt=0;
			if(d/dd<2){
				cnt=0;
			}else{
				long long jx=2*(d/dd)-1;
				cnt=n-jx;
			}
			
			cout<<cnt<<'\n';
		}
		return 0;
	}
	while(t--){
		memset(ln,0,sizeof(ln));
		memset(rn,0,sizeof(rn));
		memset(arr,0,sizeof(arr));
		long long n,cnt=0;
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>arr[i];
		}
		sort(arr+1,arr+1+n);
		arr[n+1]=(long long)4e18;
		long long ll=1,rr=1;
		for(long long i=1;i<=n;i++){
			while(arr[i]-arr[ll]>d){
				ll++;
			} 
			while(arr[rr]-arr[i]<=d){
				rr++;
			} 
			ln[i]=ll;
			rn[i]=rr-1;
		}
//		for(long long i=1;i<=n;i++){
//			cout<<ln[i]<<" "<<rn[i]<<'\n';
//		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+2;j<=n;j++){
				if(jg(i,j)) cnt++;
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
/*
11 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/

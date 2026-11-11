#include<bits/stdc++.h>
using namespace std;
#define int long long
int N,M;
int x[500005],q[500005];
bool cmp(int n,int m){
	return n<m;
}
int ans=0;
bool pd(int n1){
	int n=x[n1];
	//cout<<"n1="<<n1<<",n="<<n<<"\n";
	//cout<<n1*n-(q[n1]-q[1-1])<<"\n";
	if(n1*n-(q[n1]-q[1-1])<=M){
		ans=n1;
		//cout<<"ans="<<ans<<"\n";
		return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal1.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>N>>M;
	//cout<<"n="<<N<<",m="<<M<<"\n";
	for(int i=1;i<=N;i++){
		cin>>x[i];
		//cout<<x[i]<<" ";
	}
	//cout<<"\n\n";
	sort(x+1,x+N+1,cmp);
	for(int i=1;i<=N;i++){
		q[i]=q[i-1]+x[i];
	}
	int l=1,r=N;
	while(l<=r){
		int mid=(l+r)/2;
		//cout<<"l="<<l<<",r="<<r<<",mid="<<mid<<":\n";
		if(pd(mid)){
			l=mid+1;
			//cout<<"1\n";
		}else {
			r=mid-1;
			//cout<<"0\n";
		}
	}
	//cout<<"\n";
	cout<<ans;
	return 0;
} 

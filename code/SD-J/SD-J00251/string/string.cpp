#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const int N=2e5+10;
ll n,a[N],b[N],sum[N];
char c[N],d[N];
ll solve(int a[N],char c[N]){
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	ll k=n,q=0,cnt=0,op=sum[n]/2;
	if(sum[n]%2==1) op=sum[n]/2+1;
	for(int i=1;sum[k]+q-a[i]+1>op;i++){
		//cout<<k<<"| "<<q<<" "<<cnt<<" "<<sum[k]+q-a[i]+1<<endl;
		int t=a[i];
		if(c[k+1]!=c[i]&&q) cnt+=q;
		for(int j=k;t>0;j--){
			if(c[j]!=c[i]){
				if(a[j]<=t) cnt+=a[j],t-=a[j];
				else cnt+=t,q=a[j]-t,t=0;
			}else{
				if(a[j]<=t) t-=a[j];
				else q=a[j]-t,t=0;
			}
			k=j-1;
		}
		//cout<<"tl:"<<k<<"| "<<q<<" "<<cnt<<" "<<sum[k]+q-a[i]+1<<endl;
	}
	return cnt;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		b[n-i+1]=a[i],d[n-i+1]=c[i];
	}
	cout<<min(solve(a,c),solve(b,d));
	return 0;
}

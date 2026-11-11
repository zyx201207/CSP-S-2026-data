#include<bits/stdc++.h>
using namespace std;
long long n,m;
const int N=5e5+10;
long long a[N];
bool flag=true,flag1=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]!=i)flag=false;
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;++i){
		if(a[2]-a[1]!=a[i]-a[i-1]){
			flag1=false;
			break;
		}
	}
	if(flag){
		long long cnt=1;
		long long i=1;
		while(true){
			if(m-i<0)break;
			cnt++;
			m-=i;
			i++;
		}
		cout<<cnt<<'\n';
		return 0;
	}
	if(flag1){
		long long cnt=1;
		long long i=1;
		while(true){
			if(m-i*(a[2]-a[1])<0)break;
			cnt++;
			m-=i*(a[2]-a[1]);
			i++;
		}
		cout<<cnt<<'\n';
		return 0;
	}
	long long summ=0;
	for(int i=1;i<=n;++i){
		summ+=(a[n]-a[i]);
	}
	if(summ<=m){
		cout<<n<<'\n';
		return 0;
	}
	long long l=1,r=1,ans=0;
	while(r<=n){
		while(m>ans){
			l++;
			ans=a[r]-a[l];
			//cout<<l<<' '<<r<<' '<<ans<<'\n';
		}
		l++;
		ans=(r-l)*(a[r]-a[l-1]);
	//	cout<<l<<' '<<r<<' '<<ans<<'\n';
	}
	cout<<ans<<'\n';
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/

#include<bits/stdc++.h>
using namespace std;
const int M=2e5+5;
int a[M],sum=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	bool fg=true;
	for(int i=1;i<=n;i++){
		bool f=false;
		for(int j=0;j<30;j++){
			if(a[i]==(1<<j)-1){
				f=true;
				break;
			}
		}if(!f){
			fg=false;break;
		}
	}
	if(fg){
		cout<<a[m]<<"\n";
		return 0;
	}
	if(m==1){
		cout<<a[1]<<"\n";
		return 0;
	}
	if(m==n){
		int sum=(1<<30)-1;
		for(int i=1;i<=n;i++)sum&=a[i];
		cout<<sum<<"\n";
		return 0;
	}
	for(int i=1;i<=n-m+1;i++){
		int cum=(1<<30)-1;
		for(int j=i;j<=i+m-1;j++)cum&=a[j];
		if(cum==0)continue;
		sum=max(sum,cum);
		break;
	}
	cout<<sum<<"\n";
	return 0;
}

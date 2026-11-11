#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
ll n,m,a[N],ans,maxn,cnt,sum;
bool flag=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ans=a[1];
	for(int i=2;i<=n;i++) ans&=a[i];
	for(int i=11;i<=17;i++){
		if(pow(2,i)==n) flag=1;
	}
	if(m==n){
		cout<<ans;
	}
	else if(m==1){
		cout<<a[n];
	}
	else if(m==2){
		maxn=-1;
		for(int i=1;i<=n;i++){
			cnt=a[i];
			for(int j=i+1;j<=n;j++){
				cnt&=a[j];
				maxn=max(maxn,cnt);
			}
		}
		cout<<maxn;
	}
	else if(m==n-1){
		maxn=a[2];
		for(int i=3;i<=n;i++){
			maxn&=a[i];
		}
		cnt=a[1];
		for(int i=2;i<=n;i++){
			a[i]=a[1];
			for(int j=1;j<=n-1;j++){
				cnt&=a[j];
			}
			maxn=max(maxn,cnt);
		}
		cout<<maxn;
	}
	else if(flag) cout<<0;
	else if(n<=20){
		maxn=-1;
		for(int i=1;i<=n;i++){
			cnt=a[i];
			for(int j=i+1;j<=n;j++){
				cnt&=a[j];
				maxn=max(maxn,cnt);
			}
		}
		cout<<maxn;
	}
	else{
		sum=a[n];
		while(m--){
			sum&=a[n-m];
		}
		cout<<sum;
	}
	return 0;
}

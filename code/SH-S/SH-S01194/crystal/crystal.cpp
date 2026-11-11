#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m,a[500005],sum[500005],pre[500005];
bool flagA,flagB;
int p; 

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)flagA=1;
	}
	sort(a+1,a+n+1);
	int x=a[2]-a[1];
	for(int i=2;i<n;i++){
		if(a[i+1]-a[i]!=x)flagB=1;
	}
	if(!flagA){
		int cnt=1;
		for(int i=1;i<n;i++){
			if(m>=i){
				m-=i;
				cnt++;
			}else break;
		}
		cout<<cnt;
		return 0;
	}
	if(!flagB){
		int cnt=1;
		for(int i=1;i<n;i++){
			if(m>=i*x){
				m-=i*x;
				cnt++;
			}else break;
		}
		cout<<cnt;
		return 0;
	}
	int mx=0;
	for(int i=1;i<=n;i++){//计算用哪个数字最划算 
		for(int j=1;j<i;j++){
			pre[j]=pre[j-1]+a[i]-a[i-j];
		}
		mx=max(mx,upper_bound(pre+1,pre+i,m)-pre);
	}
	cout<<mx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

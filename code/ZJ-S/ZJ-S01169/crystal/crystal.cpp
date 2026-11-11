#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>2){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
				flag=0;
			}
		}
	} 
	if(flag){
		int k=a[2]-a[1];
		int i=1,ans=1;
		while(m>0){
			if(n-i<=0)break;
			if(n-i>0){
				if(m>=i*k){
					m-=i*k;
					ans++;
				}
				else break;
			}
			i++;
		}
		cout<<ans;
		return 0;
	}
	int mx=0;
	for(int j=n;j>=1;j--){
		int i=1,ans=1,mm=m,last=0;
//		cout<<j<<' ';
		while(mm>0){
			if(j-i<=0)break;
			if(j-i>0){
				if(mm>=last+a[j-i+1]-a[j-i]){
					mm-=(last+a[j-i+1]-a[j-i]);
					ans++;
				}
				else break;
			}
			last+=(a[j-i+1]-a[j-i]);
			i++;
		}
//		cout<<'\n';
		mx=max(mx,ans);
	} 
	cout<<mx;
	return 0;
}


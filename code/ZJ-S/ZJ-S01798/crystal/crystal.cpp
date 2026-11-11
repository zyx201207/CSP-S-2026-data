#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],ans=1,k;
void special(){
	int cnt=1,ji=1;
	while(1){
		m-=ji*k;
		if(m>=0){
			ji++;
			cnt++;
		}else{
			ans=max(ans,cnt);
			return; 
		}
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int flag=1;k=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(k!=a[i]-a[i-1]){
			flag=0;
			break;
		}
	}
	if(flag)special();
	int biao=a[1],cntx=0;
	for(int i=1;i<=n;i++){
		if(a[i]==biao){
			cntx++;
		}else{
			biao=a[i];
			ans=max(ans,cntx);
			cntx=1;
		}
	}
	cout<<ans;
	return 0;
}

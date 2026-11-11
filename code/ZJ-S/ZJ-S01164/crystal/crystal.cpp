#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans=0;
int a[500500];int cha[500500];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	cha[1]=0;sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)cha[i]=a[i]-a[i-1];
	int cnt7=1;
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1])cnt7++;
		if(cnt7>ans){
			ans=cnt7;
			continue;
		}
	}
	int cnt8=1,M=m;
	for(int i=2;i<=n;i++){
		M-=(i-1)*cha[i];
		if(M>=0)cnt8++;
		if(M<=0){
			if(M==0)for(;;){
						if(a[i]==a[i+1]){
							cnt8++;
							i+=1;
							continue;
						}
						break;
					}
			ans=max(ans,cnt8);
			break;
		}
	}
	cout << ans;
	return 0;
}

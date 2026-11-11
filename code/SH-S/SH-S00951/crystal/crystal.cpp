#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int n,ans;
ll m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		ll km=m;
		bool flag=0;
		for(int j=i;j>=1;j--){
			if(km-(a[i]-a[j])<0){
				ans=max(ans,i-j);
				flag=1;
				break;
			}km-=(a[i]-a[j]);
		}if(flag==0){
			ans=max(ans,i);
			break;
		}
	}cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

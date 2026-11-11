#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
int s[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,ans=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];s[i]=1;
	}
	sort(a+1,a+n+1);
	if(n<=5000){
		for(int i=2;i<=n;i++){
			int j=i;
			int mm=m;
			while(j>=1&&mm>=0){
				j--;
				int cha=a[i]-a[j];
				mm=mm-cha;
				if(mm<0){
					break;
				}
				s[i]++;
			}
			ans=max(ans,s[i]);
		}
	}
	else{
		int j=n;
		int mm=m;
		while(j>=1&&mm>=0){
			j--;
			int cha=a[n]-a[j];
			mm=mm-cha;
			if(mm<0){
				break;
			}
			s[n]++;
		}
		ans=s[n];
	}
	cout<<ans;
	return 0;
}

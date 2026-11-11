#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200010],cnt[200010];
bool f[500];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	long long ans=0;
	while(1){
		for(int i=0;i<=30;i++)cnt[i]=0;
		for(int i=1;i<=n;i++){
			//cout<<a[i]<<' ';
			for(int j=0;j<=30;j++){
				if(a[i]>>j&1)cnt[j]++;
			}
		}
		int s=-1;
		for(int i=30;i>=0;i--){
			//cout<<cnt[i]<<" ";
			if(cnt[i]>=m&&!f[i]){
				s=i;
				f[i]=1;
				ans+=1<<i;
				break;
			}
		}
		//cout<<'\n';
		if(s==-1)break;
		for(int i=1;i<=n;i++){
			if(((a[i]>>s)&1)==0){
				a[i]=0;
			}
		}
	}
	cout<<ans<<'\n';	
	return 0;
}
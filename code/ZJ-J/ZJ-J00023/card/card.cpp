#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
struct num{
	int used,place;
} f[maxn];
int table[maxn],ans[maxn],cnt1[maxn],cnt2[maxn];
int n,m,a[maxn];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt1[i]+=cnt1[i-1];
		cnt2[i]+=cnt2[i-1];
		if(a[i]==1)cnt1[i]++;
		if(a[i]==2)cnt2[i]++;
	}
	if(m<=2){
		int used1=0,used2=0;
		for(int i=1;i<=n;i++){
			if(i==n){
				ans[a[n]]++;
				break;
			}
			if(a[i]==1&&a[n]==1)ans[1]++;
			else if(a[i]==2&&a[n]==2)ans[2]++;
			else{
				if(cnt1[n]-cnt1[n-i-1])ans[1]++;
				if(cnt2[n]-cnt2[n-i-1])ans[2]++;
			}
		}
		cout<<ans[1]<<' '<<ans[2];
		return 0;
	}
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=0;j<=n;j++)f[j].used=f[j].place=0;
		for(int j=i;j<=n;j++){
			int val=a[j];
			if(!f[val].used){
				f[val].used=1;
				f[val].place=++cnt;
				table[cnt]=val;
			}
			else{
				int cnt2=f[val].place;
				for(int k=f[val].place+1;k<=cnt;k++){
					int p=table[k];
					f[p].used=0;
					f[p].place=0;
				}
				cnt=cnt2;
			}
		}
		for(int j=1;j<=m;j++){
			if(f[j].used)ans[j]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
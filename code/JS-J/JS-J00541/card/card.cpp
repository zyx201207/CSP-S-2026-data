#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],ans[300010],sum[300010];
struct st{
	int val,pre,nxt;
};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		st b[300010];
		b[0].nxt=1;
		memset(sum,0,sizeof(sum));
		for(int j=i;j<=n;j++){
			b[j-i+1].val=a[j];
			b[j-i+1].pre=j-i;
			b[j-i+1].nxt=j-i+2;
			if(sum[a[j]]!=0){
				b[b[sum[a[j]]].pre].nxt=j-i+1;
				b[j-i+1].pre=b[sum[a[j]]].pre;
				for(int z=sum[a[j]];z<=j-i+1;z=b[z].nxt)
					sum[b[z].val]=0;
			}
			sum[a[j]]=j-i+1;
		}
		for(int j=b[0].nxt;j<=n-i+1;j=b[j].nxt)
			ans[b[j].val]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}
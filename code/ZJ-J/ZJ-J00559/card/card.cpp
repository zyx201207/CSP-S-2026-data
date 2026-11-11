#include<bits/stdc++.h>
using namespace std;
long long n,ma=-1e9,m,cnt[300010],cnt2[300010];
struct node {
	int x,ne;
} a[500010];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		cin>>a[i].x;
	for(int i=1; i<=n; i++)
		for(int j=i+1; j<=n; j++)
			if(a[i].x==a[j].x)
				a[i].ne=j;
	for(int i=1; i<=n; i++) {
		int j=i;
		while(j<=n) {
			cnt2[a[j].x]++;
			if(a[j].ne)
				j=a[j].ne;
			j++;
		}
		for(int k=1; k<=m; k++)
			if(cnt2[k])
				cnt[k]++,cnt2[k]=0;
	}
	for(int i=1; i<=m; i++)
		cout<<cnt[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
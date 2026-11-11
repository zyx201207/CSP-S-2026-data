#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,dp[M],cnt[M],a[N],b[N]; //[i]:round，[j]:kind
bool f(){
	sort(b+1,b+n+1);
	for (int i=1;i<=n;i++){
		if (a[i]!=b[i])
			return 0;
	}
	return 1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}	
	if (f()){
		for (int i=1;i<=m;i++)
			cout<<1<<" ";
		return 0;
	}
	for (int i=1;i<=m;i++){
		dp[i]=0;	
		cnt[i]=0;
	}
	for (int k=1;k<=n;k++){
		for (int i=1;i<=m;i++)
			cnt[i]=0;
		for (int i=k;i<=n;i++){
			cnt[a[i]]++;
			if (cnt[a[i]]>1){
				for (int j=k;j<i;j++)
					cnt[a[j]]--;
			}
		}
		for (int i=1;i<=m;i++){
			if (cnt[i]==1)
				dp[i]++;
		}
	}
	for (int i=1;i<=m;i++)
		printf("%d ",dp[i]);
	return 0;
} 
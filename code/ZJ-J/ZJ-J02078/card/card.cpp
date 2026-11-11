#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
int Ans[500005];
int num[500005];
int esum[500005];
int tmp[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num[a[i]]++;
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		tmp[i]=i-sum;
		esum[a[i]]+=tmp[i];
		sum+=tmp[i];
		num[a[i]]--;
		if(num[a[i]]==0)sum-=esum[a[i]];
		Ans[a[i]]+=tmp[i];
	}
	for(int i=1;i<=m;i++)cout<<Ans[i]<<(i==m?'\n':' ');
}

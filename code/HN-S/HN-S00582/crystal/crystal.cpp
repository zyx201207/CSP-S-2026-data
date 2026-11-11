#include <bits/stdc++.h>
using namespace std;
const int N=500001;
long long a[N],b[N];

bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans[N];
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)b[j]=a[j];
		sort(b+1,b+n+1,cmp);
		int l=m,t=i;
		while(l>0){
			if(b[t]!=a[i]){
				b[t]++;
				l--;
			}
			else t++;
		}
		for(int j=1;j<=n;j++)if(b[j]==a[i])ans[i]++;
	}
	sort(ans+1,ans+n+1,cmp);
	cout<<ans[1];
	return 0;
}

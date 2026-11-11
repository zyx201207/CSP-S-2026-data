#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
int ans[N];
int to[N];
int l[N];
bool f[N];
int sum;
int t;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(f[i])continue;
		int r=i;
		sum=0;
		while(r<=n){
			sum++;
			if(f[r])sum--;
			f[r]=1;
			t=l[a[r]];
			ans[a[r]]+=sum;
			r=t+1;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
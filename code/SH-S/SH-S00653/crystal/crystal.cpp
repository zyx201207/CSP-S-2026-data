#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],pos1,pos2,maxn,ans,dc;
void solvebf(){
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int m1=m;
		ans=0;
		for(int j=i;j>=1;j--){
			if(a[i]-a[j]<=m1){
				ans++;
				m1-=(a[i]-a[j]);
			}
			else if(a[i]-a[j]>m1){
				break;
			}
		}
		maxn=max(maxn,ans);
	}
	cout<<maxn;
}
void solvedc(){
	int i=dc;
	while(1){
		if(m<i){
			cout<<ans;
			return;
		}
		if(ans>n){
			cout<<n;
			return;
		}
		else if(m>=i){
			m-=i;
			ans+=1;
		}
		i+=dc;
	}
	return;
}
bool isdc(){
	dc=abs(a[2]-a[1]);
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=dc){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(isdc())
		solvedc();
	else
		solvebf();
	return 0;
}

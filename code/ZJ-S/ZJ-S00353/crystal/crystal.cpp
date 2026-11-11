#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define MAXN 500010
int n;
LL m;
LL a[MAXN];
LL p[MAXN];
int ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i =1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	p[0]=0;
	for(int i =1;i<=n;i++){
		p[i]=a[i]+p[i-1];
	}
	LL sum=0;
	for(int i =1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(ans>=j-i+1){
				break;
			}
			sum=a[j]*(j-i+1)-(p[j]-p[i-1]);
			if(sum<=m){
				ans=j-i+1;
			}
		}
	}
	cout<<ans;
	return 0;
}

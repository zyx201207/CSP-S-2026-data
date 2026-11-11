#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,cc;
long long a[maxn];
long long m;
long long ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		ans=0;
		for(int j=i-1;j>=1;j--){
			ans+=a[i]-a[j];
			if(ans<=m){
				cc=max(cc,i-j+1);
			}else break;
		}
	}
	cout<<cc<<"\n";
	return 0;
}

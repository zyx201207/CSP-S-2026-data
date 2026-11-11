#include<bits/stdc++.h>//Trick||Treat!
using namespace std;
const int N=1e5*2+5;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m,ma=0,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(a[i],ma);
	}
	if(m==1){
		cout<<ma;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=m;j++){
				if(ans<a[i]&a[j]){
					ans=a[i]&a[j];
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
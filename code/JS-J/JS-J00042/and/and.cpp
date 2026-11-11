#include<bits/stdc++.h>
using namespace std;
const int N=20005;
long long a[N];
long long as[N][N];
long long ans=0;
long long maxn=0;
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>=maxn) maxn=a[i];
		}
		cout<<maxn;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				as[i][j]=a[i]&a[j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(as[i][j]>=ans) ans=as[i][j];
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,M=3e5;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	int a[N],sum=0,num[M];
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}	
	for(int i=1;i<=n;++i){
		sum=0;
		for(int j=i;j<=n;++j){
			if(a[j]==i){
				++sum;
			}
		}
		if(sum==1 || sum==0){
			for(int j=i;j<=n;++j){
				int l=a[j];
				num[l]+=1;
			}
		}
		else{
			int k=0;
			for(int j=n;j>=i;--j){
				if(a[j]==i){
					k=j;
					break;
				}
			}
			for(int j=k;j<=n;++j){
				int l=a[j];
				num[l]+=1;
			}
		}
	}
	for(int i=1;i<=m;++i){
		cout << num[i] << " ";
	}
	return 0;
}

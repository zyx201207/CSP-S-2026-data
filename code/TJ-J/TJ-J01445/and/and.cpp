#include <bits/stdc++.h>
using namespace std;
const long long N=2e5+5;
long long arr[N];
bool vis[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	long long ans=0;
	for(int i=31;i>=0;i--){
		int k=0;
		for(int j=1;j<=n;j++){
			if(((arr[j]>>i)&1)==1&&vis[j]==0){
				k++;
			}
		}
		if(k>=m){
			for(int j=1;j<=n;j++){
				if(((arr[j]>>i)&1)==0&&vis[j]==0){
					vis[j]=1;
				}
			}
			long long cnt=1;
			int x=i;
			while(x--){
				cnt*=2;
			}
			ans+=cnt;
		}
	}
	cout<<ans;
	return 0;
}

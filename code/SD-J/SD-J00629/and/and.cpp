#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool v[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int len=n;
	int ans=0;
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(!v[j]&&!(a[j]&(1<<i))){
				cnt++;
			}
		}
		if(len-cnt<m)continue;
		len=len-cnt;
		ans=ans+(1<<i);
		for(int j=1;j<=n;j++){
			if(!(a[j]&(1<<i))){
				v[j]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}

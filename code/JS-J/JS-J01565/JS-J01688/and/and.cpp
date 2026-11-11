#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001];
bool b[200001][31];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int lastb=0,ans=0;
	for(int i=30;i>=0;i--){
		int x=1<<i,cnt=0;
		for(int j=1;j<=n;j++){
			if(b[j][lastb]){
				b[j][i]=1;
				continue;
			}
			if((a[j]&x)){
				cnt++;
			}
			else{
				b[j][i]=1;
			}
		}
		if(cnt>=m){
			lastb=i;
			ans+=x;
		}
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,m,a[MAXN],maxx=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=2;i<=n;i++){
		int t=m,cnt=0;
		for(int j=i;j>=1;j--){
			if(t-(a[i]-a[j])>=0){
				t-=(a[i]-a[j]);
				cnt++;
			}
		}
		maxx=max(maxx,cnt);
	}
	cout<<maxx;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=5e5+10;
pair<int,int> s[N];
int n,a[N],ans[300010],m,b[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	int x=n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		ans[a[i]]=i;
		b[a[i]]++;
	}
	if(m<=2){
		if(b[a[n]>1]){
			if(a[n]==1){
				cout << n << " " << 0;
			}
			else{
				cout << 0 << " " << n;
			}
		}
		else{
			if(a[n]==1){
				cout << n << " " << n-1;
			}
			else{
				cout << n-1 << " " << n;
			}
		}
		return 0;
	}
	if(n==m){
		for(int i=1;i<=n;i++){
			cout << i << " ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(s[a[j]].first){
				for(int k=s[a[j]].second+1;k<j;k++){
					s[a[k]].first=0;
					s[a[k]].second=0;
				}
				s[a[j]].second=j;
			}
			else{
				s[a[j]].first=1;
				s[a[j]].second=j;
			}
		}
		for(int j=i;j<=m;j++){
			if(s[j].first==0) ans[j]--;
		}
		for(int j=i;j<=n;j++){
			s[a[j]].first=s[a[j]].second=0;
		}
	}
	for(int i=1;i<=m;i++) cout << ans[i] <<" ";
	return 0;
}


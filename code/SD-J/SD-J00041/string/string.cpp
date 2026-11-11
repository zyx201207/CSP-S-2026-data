#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+7;
int n,a[maxn],b[maxn];
ll ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		string s;
		cin >> s;b[i]=s[0]-'a';
	}
	for(int l = 1,r = n;l<r;l++){
		while(a[l]>0){
			int mi = min(a[l],a[r]);
			a[l]-=mi,a[r]-=mi;
			if(b[l]!=b[r])ans+=mi;
			if(a[r]==0)r--;
		}
	}
	cout << ans << "\n";
	return 0;
}

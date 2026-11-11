#include<bits/stdc++.h> 
using namespace std;
using ll = long long;
int n,m,ans;
string a[200008];
void dfs(int t,int d,string vl){
	if(t > m){
		int tvl = 0,q = 0,vls = vl.size();
		for(int i = vls-1;i >= 0;i--,q++){
			if(vl[i] == '1') tvl += pow(2,q);
		}
		ans = max(ans,tvl);
		return;
	}
	for(int i = d+1;i <= n;i++){
		string vl2 = "";
		int vls = vl.size(),ais = a[i].size();
		if(vls > ais) while(vl.size() != a[i].size()) a[i] = '0'+a[i];
		if(vls < ais) while(vl.size() != a[i].size()) vl = '0'+vl;
		for(int j = vls-1;j >= 0;j--){
			if(a[i][j] == vl[j] && vl[j] == '1') vl2 = '1'+vl2;
			else vl2 = '0'+vl2;
		}
		dfs(t+1,i,vl2);
	}
	return;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		ll x;
		string s;
		cin >> x;
		for(int j = 0;x >= 1;j++){
			if(x % 2 != 0) s = '1'+s;
			else s = '0'+s;
			x /= 2;
		}
		a[i] = s;
	}
	for(int i = 0;i < n;i++)
		dfs(1,i,"111111111111111111111111111111");
	printf("%d",ans);
	return 0;
}

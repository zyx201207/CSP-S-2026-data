#include<bits/stdc++.h>
#define ull unsigned long long
#define INF ULLONG_MAX
using namespace std;

vector<ull> a;
int n;
ull m;
ull minele=INF, maxele=0;
bool speA=1,speB=1;
int speBh=INF;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	//code area
	cin>>n>>m;
	a.reserve(n);
	for(int i=0;i<n;i++) {
		ull thisa=0;
		cin>>thisa;
		maxele=max(maxele,thisa);
		minele=min(minele,thisa);
		a.push_back(thisa);
		if((i+1)!=thisa) speA=0;
		if(i==1) speBh=thisa-a[i-1];
		else if(i>2 && thisa-a[i-1]!=speBh) speB=0;
	}
	if(speA){
		int ans = (int)(sqrt(1+4*m)-1)+1;
		if(ans<=n) cout<<ans;
		else cout<<n;
		return 0;
	}
	if(speB){
		int ans = (int)((int)(sqrt(1+4*m*speBh)-1)/speBh)+1;
		if(ans<=n) cout<<ans;
		else cout<<n;
		return 0;
	}
	int tot=0; //O(
	for(int i=minele;i<=maxele;i++){
		priority_queue<int,vector<int>,greater<int>> helper={};
		for(auto item : a){
			helper.push(abs((long long)item-i));
		}
		int o=0,ans=0;
		while(!helper.empty()&&o<=m){
			o+=helper.top();
			helper.pop();
			ans++;
		}
		if(o>m) ans--;
		tot=max(tot,ans);
	}
	cout<<tot;
	return 0;
}


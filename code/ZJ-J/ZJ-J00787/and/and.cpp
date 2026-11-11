#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int n,m;
int a[maxn];
//vector<int> bcnt[32];
bool ok=1;
int ans;
vector<int> ch,ls;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	/*
	for(int i=0;i<=31;i++){
		for(int j=1;j<=n;j++){
			if(a[j]&(1<<i)){
				bcnt[i].push_back(j);
			}
		}
	}*/
	int stw=-1;
	for(int i=31;i>=1;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(a[j]&(1<<i)){
				cnt++;
			}
		}
		if(cnt>=m){
			stw=i;
			break;
		}
	}
	if(stw==-1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]&(1<<stw)){
			ch.push_back(i);
		}
	}
	ans+=(1<<stw);
	//cout<<"ans:"<<ans<<" stw:"<<stw<<'\n';
	for(int i=stw-1;i>=0;i--){
		int cnt=0;
		for(int j=0;j<ch.size();j++){
			int k=ch[j];
			//cout<<i<<" k:"<<k<<" ak:"<<a[k]<<'\n';
			if(a[k]&(1<<i)){
				cnt++;
				ls.push_back(k);
			}
		}
		if(cnt>=m){
			ans+=(1<<i);
			ch.clear();
			for(int j=0;j<ls.size();j++){
				ch.push_back(ls[j]);
			}
			//cout<<"i:"<<i<<" cnt:"<<cnt<<" ans:"<<ans<<'\n';
		}
	}
	cout<<ans;
	return 0;
}

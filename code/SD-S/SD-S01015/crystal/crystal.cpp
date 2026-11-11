#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m;
int crystal[500050];
int ans[100010],anss;
bool special=1;
void sp(int l){
	int ans=1,cnt=l;
	while(m>=cnt){
		ans++;
		m-=cnt;
		cnt+=l;
	}cout<<ans;
	return;
}
signed main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int l=0;
	for(int i=1;i<=n;i++){
		cin>>crystal[i];
	}sort(crystal+1,crystal+1+n);
	l=crystal[2]-crystal[1];
	for(int i=3;i<=n;i++){
		if(crystal[i]-crystal[i-1]!=l)special=0;
	}
	if(special){sp(l);return 0;}
	for(int i=1;i<=n;i++){int cnt=0;
		for(int j=i-1;j>0;j--){
			
			ans[i]++;cnt+=crystal[i]-crystal[j];
			if(cnt>m){
				ans[i]--;break;
			}
		}
	}for(int i=1;i<=n;i++){
		anss=max(anss,ans[i]);
	}cout<<anss+1;
	return 0;
}

//Oct31==Dec25?

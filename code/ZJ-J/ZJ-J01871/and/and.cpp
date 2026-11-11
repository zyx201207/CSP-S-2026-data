#include<bits/stdc++.h>
using namespace std;
long long a[200005];
string s[200005];
string jz2(long long x){
	string s2="";
	while(x){
		s2=char('0'+x%2)+s2;
		x/=2;
	}
	return s2;
}
bool vis[200005][33];
bool fl[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		fl[i]=true;
		cin>>a[i];
		s[i]=jz2(a[i]);
		int sz=s[i].size();
		for(int j=0;j<sz;j++){
			if(s[i][sz-j-1]=='1')vis[i][j]=true;
		}
	}
	for(int i=32;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(vis[j][i]&&fl[j])cnt++;
		}
		if(cnt>=m){
			for(int j=1;j<=n;j++){
				if(!vis[j][i]&&fl[j])fl[j]=false;
			}
		}
		else if(cnt==m)break;
	}
	long long ans=-1;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(ans==-1&&fl[i]){
			ans=a[i];
			cnt++;
		}
		else if(fl[i]){
			ans=ans&a[i];
			cnt++;
		}
		if(cnt==m)break;
	}
	cout<<ans;
	
	return 0;
}

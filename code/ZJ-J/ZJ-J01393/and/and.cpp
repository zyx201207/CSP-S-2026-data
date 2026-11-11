#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int maxn=2e5+5;
int n,m,cnt[maxn],a[maxn],ans[maxn],sum=0;
string b[maxn];
vector<int>g[maxn];
bool flag=0;
string fun(int x){
	string s="";
	while(x){
		if(x%2==1){
			s+='1';
		}
		else{
			s+='0';
		}
		x/=2;
	}
	string c="";
	for(int i=s.size();i<=33;i++){
		c+='0';
	}
	for(int i=s.size()-1;i>=0;i--){
		c+=s[i];
	}
	return c;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=fun(a[i]);
	}
	for(int i=0;i<=33;i++){
		for(int j=1;j<=n;j++){
			if(b[j][i]=='1'){
				g[i].push_back(j);
			}
			cnt[i]+=(b[j][i]-'0');
		}
	}
//	for(int i=0;i<=33;i++){
//		cout<<cnt[i]<<" ";
//	}
	for(int i=1;i<=n;i++){
		ans[i]=1;
	}
	sum=n;
	for(int i=0;i<=33;i++){
		if(cnt[i]>=m){
			flag=1;
		}
		if(flag==0){
			continue;
		}
		for(auto j:g[i]){
			if(ans[j]!=-1){
				ans[j]++;
			}
		}
		for(int j=1;j<=n;j++){
			if(ans[j]==1){
				sum--;
				ans[j]=-1;
			}
			if(ans[j]>=2){
				ans[j]=1;
			}
			if(sum<=m){
				break;
			}
		}
		if(sum<=m){
			break;
		}
	}
	int tmp=-1,t=0;
	for(int i=1;i<=n;i++){
		if(ans[i]>=1){
//			cout<<ans[i]<<'\n';
			if(tmp==-1){
				t++;
				tmp=a[i];
			}
			else{
				t++;
				tmp=tmp&a[i];
			}
		}
		if(t>=m){
			break;
		}
	}
	cout<<tmp<<'\n';
	return 0;
}


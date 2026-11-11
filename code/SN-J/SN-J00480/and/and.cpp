//Time 9:04-10:15 By MingDynasty
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,e[323232];
inline string to2bit(int x){
	string h="";
	while(x){
		h+=(x%2?'1':'0');
		x/=2;
	}
	return h;
}
vector<string>h;
bool strcmp(string a,string b){
	if(a.size()>b.size()) return 1;
	if(b.size()>a.size()) return 0;
	for(int i=0;i<a.size();i++){
		if(a[i]=='0'&&b[i]=='1') return 0;
		if(a[i]=='1'&&b[i]=='0') return 1;
	}
	return 1;
}
inline int to10bit(string x){
	int ans=0,k=1;
	for(int i=0;i<x.size();i++){
		if(x[i]=='1') ans+=k;
		k*=2;
	}
	return ans;
}
inline int kc(int f,string h){
	string o=to2bit(f);
	if(o.size()!=h.size()){
		string bq="";
		for(int i=0;i<=min(h.size(),o.size());i++){
			bq+="0";
		}
		if(h.size()<o.size()){
			h=bq+h;
		}else o=bq+o;
	}
	int fk=1,ans=0;
//	cout<<"Compare :"<<h<<"As 1!\n";
//	cout<<"Compare :"<<o<<"As 2!\n";
	for(int i=h.size()-1;i>=0;i--){
		if(h[i]==o[i]) ans+=fk;
		fk*=2;
//		cout<<"Report from #"<<i;
//		if(h[i]==o[i]) cout<<":OK(TRUE),FK:"<<fk<<'\n';
//		else cout<<":NO,FK:"<<fk<<'\n';
	}
	return ans;
}
bool vis[33];
inline int dfs(int ans,int x){
	if(x==m){
		return ans;
	}
	int ans2=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			ans2=max(ans2,dfs((ans&e[i]),x+1));
			vis[i]=0;
		}
	}
	return ans2;
}
//struct Node{l
//	vector<int>k;
//	inline void push_back(string h){
//		
//	}
//};
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
//	cout<<3&5;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>e[i],h.push_back(to2bit(e[i]));
	if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++) ans=max(ans,e[i]);
		cout<<ans;
		exit(0);
	}
	if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(e[i]&e[j]));
			}
		}
		cout<<ans;
		exit(0);
	}
	if(m==n){
		int ans=e[1];
		for(int i=2;i<=n;i++)ans&=e[i];
		cout<<ans;
		exit(0);
	}
	if(n<=20){
		int ans=0;
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof vis);
			vis[i]=1;
			ans=max(ans,dfs(e[i],1));
		}
		cout<<ans;
		exit(0);
	}
	//50pts
//	int maxn=0;
//	for(int i=0;i<h.size();i++) maxn=max(maxn,(int)h[i].size());
//	for(int i=0;i<h.size();i++){
//		if(h[i].size()<maxn){
//			string p="";
//			for(int i=1;i<=maxn-h[i].size();i++) p+='0';
//			h[i]=p+h[i];
//		}
//	}
	sort(e+1,e+1+n,greater<int>());
	int ans=e[1];
	for(int i=2;i<=m;i++)ans=(ans&e[i]);
	cout<<ans;
//	sort(h.begin(),h.end());
//	reverse(h.begin(),h.end());
//	int cnt=0,ans=to10bit(h[0]);
//	for(int i=1;i<m;i++){
//		ans=kc(ans,h[i]);
//		cout<<"Cheosed Number :"<<h[i]<<",ans its 10bit is "<<to10bit(h[i])<<'\n';
//	}
////	cout<<kc(1,"111");
////	for(string it:h){
////		cnt++;
////		if(cnt==m) break;
////		ans=kc(ans,it);
////		cout<<"Chosed Number :"<<it<<",ans its 10bit is"<<to10bit(it)<<'\n';
////	}
//	cout<<ans;
	return 0;
} 

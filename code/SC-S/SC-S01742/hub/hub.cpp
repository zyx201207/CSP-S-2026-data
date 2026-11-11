#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,ans,f[30],o[30][30];
vector<int>s,mp[30];
int getf(int x){
	if(f[x]==x)return x;
	return f[x]=getf(f[x]);
}
void kks(int x){
	if(x==n+1){
		if(s.size()!=k)return ;
		bool book[31],cnt=s.size();
		for(int i=0;i<=n;i++)book[i]=0;
		for(int i=0;i<s.size();i++)book[s[i]]=1;
		for(int i=0;i<=n;i++)f[i]=i;
		for(int i=0;i<s.size();i++){
			for(int p=0;p<mp[s[i]].size();p++){
				if(book[mp[s[i]][p]]&&getf(mp[s[i]][p])!=getf(s[i])){
					f[getf(mp[s[i]][p])]=getf(s[i]);
					cnt-=1;
				}
			}
		}
		if(cnt>2)return ;
		int po[30][30];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				po[i][j]=o[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int q=1;q<=n;q++){
					po[j][q]=min(po[j][q],po[j][i]+po[i][q]);
				}
			}
		}
		int mn=-1e9;
		for(int i=1;i<=n;i++){
			int kq=1e9;
			for(int j=0;j<s.size();j++){
				kq=min(kq,po[i][s[j]]);
			}
			mn=max(mn,kq);
		}
		ans=min(ans,mn);
		return ;
	}
	if(s.size()<k)s.push_back(x),kks(x+1),s.pop_back();
	kks(x+1);
	return ;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t){
		t--;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				o[i][j]=1e9;
				o[i][i]=o[j][j]=0;
			}
		}
		for(int i=0;i<=n;i++){
			while(!mp[i].empty())mp[i].pop_back();
		}
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			o[u][v]=o[v][u]=1;
			mp[u].push_back(v);mp[v].push_back(u);
		}
		ans=1e9;
		while(!s.empty())s.pop_back();
		kks(1);
		cout<<ans<<endl;
	}
}
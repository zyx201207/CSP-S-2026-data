//十年OI一场空，不开long long见祖宗
//多测不清空，爆零两行泪
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+3;
int c,t,n,k,u,v,hd[N],nxt[N*2],val[N*2],tot,ans,fx[N],f[N];
queue<int>q;
void kkksc03_an_lian_chen_zhe(int u,int v){
	val[++tot]=v;
	nxt[tot]=hd[u];
	hd[u]=tot;
}
void kkksc03_is_gay(int x){
	f[x]=1;
	for(int i=hd[x];i;i=nxt[i])
		if(f[val[i]]==0&&fx[val[i]]==1)kkksc03_is_gay(val[i]);
}
void chen_zhe_is_gay(int x){
	if(x>n){
		int cnt=0,cntf=0;
		for(int i=1;i<=n;i++)f[i]=0;
		for(int i=1;i<=n;i++)
			if(fx[i]==1&&f[i]==0){
				cnt++;
				kkksc03_is_gay(i);
			}
		for(int i=1;i<=n;i++)if(fx[i]==1)cntf++;
		if(cnt>2||cntf==0||cntf>k)return;
		while(q.size())q.pop();
		for(int i=1;i<=n;i++)
			if(fx[i]==1)q.push(i);
		int res=0,ben=0;
		while(q.size()){
			ben++;
			int sz=q.size();
			while(sz--){
				int tp=q.front();
				q.pop();
				for(int i=hd[tp];i;i=nxt[i]){
					if(f[val[i]]==0){
						res=max(res,ben);
						f[val[i]]=1;
						q.push(val[i]);
					}
				}
			}
		}
		ans=min(ans,res);
		return;
	}
	fx[x]=1;
	chen_zhe_is_gay(x+1);
	fx[x]=0;
	chen_zhe_is_gay(x+1);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		tot=0;
		ans=INT_MAX;
		for(int i=0;i<=1e6;i++)hd[i]=0,fx[i]=0,f[i]=0;
		for(int i=0;i<=2e6;i++)val[i]=0,nxt[i]=0;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			kkksc03_an_lian_chen_zhe(u,v);
			kkksc03_an_lian_chen_zhe(v,u);
		}
		chen_zhe_is_gay(1);
		cout<<ans<<endl;
	}
	return 0;
}
//哪个gay出的题目？？？？？？
//78行
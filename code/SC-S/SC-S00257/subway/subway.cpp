#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int c;
int n,m,d,q;
int k[N];
int w[N];
int g[N][N];
int ans=1e7;
struct st{
	int a;	
	vector<pair<int,int>>im;
}s[N];
void mem(){
	memset(w,0,sizeof(w));
	memset(k,0,sizeof(k));
	memset(g,0,sizeof(g));
}
void input(){
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int l;
			cin>>s[j].a>>l;
			s[j].im.push_back({k[i],l});
			if(j>1){
				g[s[j].a][s[j-1].a]=1;
				g[s[j-1].a][s[j].a]=1;
			}
		}
	}
}
int find(int f){
	for(int i=1;i<=m;i++)
		if(s[i].a==f)
			return i;
}

void dfs(int now,int end,int fa,int t,int line)
{
	if(now==end) {
		ans=min(ans,t);
		return ;
	}
	else{
		for(int i=1;i<=m;i++)
		{
			if(g[now][i]==1&&i!=fa)
			{
				int idx=find(fa),idy=find(i),self=find(now);
				for(int a=0;a<s[idx].im.size();a++){
					for(int b=0;b<s[idy].im.size();b++){
						if(s[idx].im[b].first==s[idy].im[b].first){
							dfs(i,end,now,t,line);
						}
						else
						{
							int zzz;
							for(int c=0;c<s[self].im.size();c++){
								if(s[self].im[c].first==s[idy].im[b].first)
									zzz=s[self].im[c].second;
							}
							for(int c=0;c<s[self].im.size();c++){
								if(s[self].im[c].first==line)
									zzz+=s[self].im[c].second;
							}
							dfs(i,end,now,t+zzz,s[idy].im[b].first);
						}
							
					}
				}
				
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.ans","w",stdout);
	cin>>c;
	if(c==0) c=1;
	while(c--){
		mem();
		input();
		
		while(q--){
			int bg,ed;
			cin>>bg>>ed;
			cout<<'\n';
			for(int i=0;i<s[find(bg)].im.size();i++)
				dfs(bg,ed,0,s[find(bg)].im[i].second,s[find(bg)].im[i].first);
				
			cout<<ans<<'\n';
		}
		
		
	}
	return 0;
}
/*/
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


/*/
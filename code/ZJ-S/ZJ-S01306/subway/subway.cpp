#include<bits/stdc++.h>
#define int long long
using namespace std;

namespace myrun1to6{
	inline int read(){
		int c=getchar(),f=1,s=0;
		while(c<'0'||c>'9'){
			if(c=='-') f=-1;
			c=getchar();
		}
		while(c>='0'&&c<='9'){
			s=s*10+(c^48);
			c=getchar();
		}
		return f*s;
	}
	int test_c,n,m,d_max,q;
	signed btime[500005];
	vector<pair<signed,signed> >ve1[500005];
	signed readx,ready;
	int dis[1005][1005];
	signed main(){
		n=read();m=read();d_max=read(),q=read();
		for(int i=1;i<=m;i++){
			btime[i]=read();
		}
		for(int i=1;i<=n;i++){
			int k=read();
			for(int j=1;j<=k;j++){
				readx=read();
				ready=read();
				ve1[readx].push_back(make_pair(i,ready));
			}
		}//have to
		memset(dis,0x3f,sizeof(dis));
		for(int i=1;i<=m;i++){
			int lens=ve1[i].size();
			for(int v_i=0;v_i<lens;v_i++){
				pair<signed,signed>v=ve1[i][v_i];
				dis[v.first][v.first]=0;
//				btime[i][v.first]=btime[i][0]+v.second;
				for(int u_i=v_i+1;u_i<lens;u_i++){
					pair<signed,signed>u=ve1[i][u_i];
					dis[u.first][v.first]=dis[v.first][u.first]=min(dis[v.first][u.first],(int)v.second+(int)u.second);
				}
			}
		}//O(m*d*d)
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dis[j][i]=dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}				
			}
		}//O(n^3) 
		while(q--){
			int st_p=read(),ed_p=read(),ans=0x3f3f3f3f3f3f3f3f;
			for(auto va:ve1[st_p]){
				for(auto ua:ve1[ed_p]){
					signed v=va.first,u=ua.first;
					ans=min(ans,dis[v][u]+(int)btime[st_p]+(int)btime[ed_p]+(int)va.second+(int)ua.second);
				}
			}
			printf("%lld\n",ans);
			//O(d*d)
		}
		return 0;
	}
}

namespace my{
	inline int read(){
		int c=getchar(),f=1,s=0;
		while(c<'0'||c>'9'){
			if(c=='-') f=-1;
			c=getchar();
		}
		while(c>='0'&&c<='9'){
			s=s*10+(c^48);
			c=getchar();
		}
		return f*s;
	}
	int test_c;
	signed main(){
		test_c=read();
		
		return myrun1to6::main();
		
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	return my::main();
}


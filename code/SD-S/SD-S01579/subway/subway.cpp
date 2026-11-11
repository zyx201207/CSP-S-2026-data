#include<bits/stdc++.h>
using namespace std;
int w[500005];
struct s{
	int a,t;
};
vector<s> v[500];
inline int read(){
	int x=0,y=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')y=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*y;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=read(),m=read(),n=read(),d=read(),q=read();
	for(int i=1;i<=n;i++)w[i]=read();
	for(int i=1;i<=m;i++){
		int k=read();
		while(k--){
			int a=read(),t=read();
			v[i].push_back({a,t});
		}
	}
	while(q--){
		int x=read(),y=read(),idi=-1,idj=-1,ans=0;
		ans+=w[x]+w[y];
		for(int i=1;i<=m;i++){
			for(int j=0;j<v[i].size();j++)if(v[i][j].a==x){
					idi=i,idj=j;
					break;
			}
			if(idi!=-1)break;
		}
		for(int i=idj;i<v[idi].size();i++){
			ans+=v[idi][i].t;
			if(v[idi][idj].a==y)break;
		}
		cout<<ans<<'\n';
	}
	return 0;
}

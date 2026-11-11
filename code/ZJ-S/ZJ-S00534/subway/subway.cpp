#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,d,qq,w[500005],s1,s2,shijian[500005],v[500005],q[500005][2],f=1,e=1,ans;//weizhi shijian
int cnt,h[500005],nxt[500005],val[500005],to[500005];
struct st{
	int shu,zhan[105];
}a[505];
void find(){
	q[1][0]=s1,q[1][1]=w[s1]+shijian[s1]+w[s2],v[s1]=0;
	while(f<=e){
		for(int i=h[q[f][0]];i;i=nxt[i]){
			if(v[to[i]])continue;
			v[to[i]]=1;
			e++,q[e][0]=to[i],q[e][1]=q[f][1]+val[i];
			if(q[e][0]==s2){
				ans=min(ans,q[e][1]);
				return;
			}
		}
		f++;
	}
}
void add(int u,int v,int w){
	cout<<u<<" "<<v<<" "<<w<<'\n';
	cnt++,shijian[v]=w;
	val[cnt]=w,to[cnt]=v;
	nxt[cnt]=h[u],h[u]=cnt;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].shu;
		for(int j=1;j<=a[i].shu;j++){
			cin>>a[i].zhan[j*2-1]>>a[i].zhan[j*2];
		}
		for(int j=1;j<=a[i].shu;j++){
			for(int k=j+1;k<=a[i].shu;k++){
				add(j,k,a[i].zhan[k*2]);
				add(k,j,a[i].zhan[j*2]);
			}
		}
	}
	while(qq--){
		memset(v,0,sizeof(v));
		cin>>s1>>s2;
		ans=INT_MAX;
		find();
		cout<<ans<<'\n';
	}
	return 0;
}
//15:00-15:35 write a baoli but it's wrong,so i delete all code
//16:00-16:20 think about this(and other) problem
//17:25 try to write special xingzhi A(1000 bian zui duan lu)

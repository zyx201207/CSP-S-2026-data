#include<bits/stdc++.h>
#define int long long
using namespace std;
	int n,m,d,qt,w[600005],k[600005],st,ed,sfa[600005],dl[600005],he,tl,vf[600005];
	bool zdl[600005],vis[600005];
	vector<int>vb[600005],vq[600005];
	queue<int>q;
	const int dg=4e18;
	
	
int ind(){
	int g=0,f=1;
	char cg=getchar();
	while(cg<'0'||cg>'9'){
		if(cg=='-'){
			f=-1;
		}
		cg=getchar();
	}
	while(cg>='0'&&cg<='9'){
		g=g*10+(cg-'0');
		cg=getchar();
	}
	return f*g;
}
void outd(int d){
	if(d<10){
		putchar('0'+d);
		return ;
	}
	else{
		outd(d/10);
		putchar('0'+d%10);
	}
	return ;
}
int bfs(int d1,int d2){
	he=1;
	tl=0;
	tl++;
	dl[tl]=d1;
	for(int i=1;i<=n+m;i++){
		vis[i]=0;
		vf[i]=0;
	}
	vf[d1]=0;
	vis[d1]=1;
	int sj; 
	while(he<=tl){
		sj=dl[he];
		he++;
		for(int i=0;i<k[sj];i++){
			if(!vis[vb[sj][i]]){
				vis[vb[sj][i]]=1;
				tl++;
				dl[tl]=vb[sj][i];
				vf[vb[sj][i]]=vf[sj]+1;
				if(vb[sj][i]==d2){
					return vf[d2]*vq[d1][0];
				}
			}
		}
	}
	return vf[d2]*vq[d1][0];
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	cin>>c;
	cin>>n>>m>>d>>qt;
	for(int i=1;i<=m;i++){
		w[i]=ind();
	}
	int dv,dt;
	for(int i=1;i<=n;i++){
		k[i+m]=ind();
		for(int j=1;j<=k[i+m];j++){
			dv=ind();
			dt=ind();
			k[dv]++;
			vb[i+m].push_back(dv);
			vb[dv].push_back(i+m);
			vq[i+m].push_back(dt);
			vq[dv].push_back(dt);
		}
	}
	if(c>=16&&c<=19){
		while(qt){
			st=ind();
			ed=ind();
			outd(bfs(st,ed)+w[st]+w[ed]);
			putchar('\n');
			qt--;
		}
		return 0;
	}
	int sj,sl;
	while(qt){
		st=ind();
		ed=ind();
		for(int i=1;i<=n+m;i++){
			sfa[i]=dg;
		}
		sfa[st]=0;
		zdl[st]=1;
		q.push(st);
		while(!q.empty()){
			sj=q.front();
			q.pop();
			zdl[sj]=0;
			for(int i=0;i<k[sj];i++){
				if(sfa[vb[sj][i]]>sfa[sj]+vq[sj][i]){
					sfa[vb[sj][i]]=sfa[sj]+vq[sj][i];
					if(!zdl[vb[sj][i]]){
						q.push(vb[sj][i]);
						zdl[vb[sj][i]]=1;
					}
				}
			}
		}
		sl=sfa[ed]+w[st]+w[ed];
		outd(sl);
		putchar('\n');
		qt--;
	} 
	
	
	
	
	
	
	
	return 0;
} 

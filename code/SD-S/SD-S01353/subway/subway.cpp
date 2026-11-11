#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int t[500005][20],w[500005];
struct N{
	vector <int> c;
};
struct S{
	vector <int> s;
	map <int,int> t2;
};
N sta[500005];
S sub[505];
void dfs(int tm,int s,int st,int ed){
	
	int ns;
	for(int i=0;i<sizeof(sta[st].c);i++){
		if(sta[st].c[i]==s){
			ns=i;
			break;
		} 
	}
	t[st][ns]=min(t[st][ns],tm);
	if(st==ed)return ;
	//cout<<ns;
	for(int i=0;i<=20;i++){
		//cout<<sizeof(sta[st].c);
		if(sta[st].c[i]==0){
			break;
		}
		int t1=t[st][ns];
		int t2=sub[s].t2[st];
		int tt=sta[st].c[i];
		if(sub[tt%500005].s.empty()){//1111111111
			break;
		}
		int t3=sub[tt].t2[st];//1
		int tmp=t1+t2+t3;
		//cout<<tmp;
		

		
		if(t[st][i]>tmp&&i!=ns){
			t[st][i]=tmp;
			dfs(t[st][i],sta[st].c[i],st,ed);
		}
	}
	for(int i=0;i<sizeof(sub[s].s);i++){
		//cout<<1;
		if(sub[s].s[i]==st){
			//cout<<1;
			dfs(tm,s,sub[s].s[i+1],ed);
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			//cout<<j;
			int a,b;
			cin>>a>>b;
			sub[i].s.push_back(a);
			sub[i].t2[a]=b;
			sta[a].c.push_back(i);
		}
	}
	//cout<<sub[1].t2[1];
	for(int f=1;f<=q;f++){
		for(int j=0;j<500005;j++){
			for(int k=0;k<=20;k++){
				t[j][k]=INT_MAX;
			}
		}
		int st,ed;
		cin>>st>>ed;
		for(int i=0;i<sizeof(sta[st].c);i++){
			dfs(w[sta[st].c[i]]+sub[sta[st].c[i]].t2[st],sta[st].c[i],st,ed);
		}
		int mi=99999999;
		for(int i=0;i<sizeof(sta[ed].c);i++){
			mi=min(mi,w[sta[ed].c[i]]+t[ed][i]);
		}
		cout<<mi; 

	}
	return 0;
}


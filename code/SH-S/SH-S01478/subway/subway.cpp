#include<bits/stdc++.h>
using namespace std;
bool ok[500509],flg[500509];
int w[500009];
long long c,n,m,d,q,ds[500509];
struct edge{
	long long u,v,dis;
	bool operator<(const edge&a)const{
		return dis<a.dis;
	}
};
vector <edge>mp[500509];
void add(long long u,long long v,long long dis){
	edge tmp;
	tmp.u=u;
	tmp.v=v;
	tmp.dis=dis;
	mp[u].push_back(tmp);
	tmp.u=v;
	tmp.v=u;
	mp[v].push_back(tmp);
}
void dij(long long st){
	queue<long long> s;
	s.push(st);
	for(long long i=1;i<=n+m;i++){
		ok[i]=0;
		ds[i]=0;
		flg[i]=0;
	}
	while(!s.empty()){
		//cout<<"back"<<s.back()<<endl;
		long long no=s.front();
		long long sz=mp[no].size();
		s.pop();
		long long nxt=0,tmp=9982443539;
		ok[no]=1;
		//sort(mp[no],mp[no]+sz,cmp3);
		for(long long i=0;i<sz;i++){
			if(!ok[mp[no][i].v]){
				ds[mp[no][i].v]=ds[no]+mp[no][i].dis;
				/*if(mp[no][i].dis<tmp){
					tmp=mp[no][i].dis;
					nxt=mp[no][i].v;
				}*/
			}
		}
		for(int i=0;i<sz;i++){
			for(int j=0;j<sz;j++){
				if(mp[no][j].dis<tmp and !flg[mp[no][j].v] and !ok[mp[no][j].v]){
					tmp=mp[no][j].dis;
					nxt=mp[no][j].v;
				}
			}
			flg[nxt]=1;
			if(nxt!=0){
				//cout<<"nxt"<<nxt<<endl;
				s.push(nxt);
			}
			nxt=0,tmp=9982443539;
		}
		
	}
}
struct query{
	long long sta,ed,id,ans;
};
query qu[100009];
bool cmp1(const query&a,const query&b){
	return a.sta<b.sta;
}
bool cmp2(const query&a,const query&b){
	return a.id<b.id;
}
bool cmp3(const edge&a,const edge&b){
	return a.dis<b.dis;
}
long long ki,ai,ti;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c;
	cin>>n;
	cin>>m;
	cin>>d;
	cin>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>ki;
		for(long long j=1;j<=ki;j++){
			cin>>ai>>ti;
			add(i,n+ai,ti);
		}
	}
	for(long long i=1;i<=q;i++){
		cin>>qu[i].sta>>qu[i].ed;
		qu[i].id=i;
	}
	sort(qu+1,qu+q+1,cmp1);
	long long tmp=qu[1].sta;
	long long las=0;
	for(long long i=1;i<=n;){
		las=i;
		while(tmp==qu[i].sta){
			i++;
		}
		dij(tmp+n);
		tmp=qu[i].sta;

		/*for(int j=1;j<=m+n;j++){
			cout<<ds[j]<<endl;
		}*/
		for(long long j=las;j<i;j++){
			qu[j].ans=ds[qu[j].ed+n];
		}
	}
	sort(qu+1,qu+q+1,cmp2);
	for(long long i=1;i<=q;i++){
		cout<<qu[i].ans+w[qu[i].sta]+w[qu[i].ed]<<endl;
	}
	return 0;
}

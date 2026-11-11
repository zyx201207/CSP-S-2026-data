#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,t,n,k;
vector<int> e[N]; 
int sp,ep,mp,mx,num;
int d[N],pre[N],cnt;
void dfs1(int u,int fa,int dep){
	if(dep>mx){
		dep=mx;
		sp=u;
	}
	for(auto x:e[u]){
		if(x==fa) continue;
		dfs1(x,u,dep+1);
	}
}
void dfs2(int u,int fa){
	for(auto x:e[u]){
		if(x==fa) continue;
		pre[x]=u;
		d[x]=d[u]+1;
		dfs2(x,u);
	}
	if(d[u]>mx){
		ep=u;
		mx=d[u];
	}
}
void bfs(int x){
	queue<int> q;
	q.push(x);
	d[x]=0;
	while(q.size()){
		int p=q.front();
		q.pop();
		for(auto x:e[p]){
			if(d[x]!=-1) continue;
			d[x]=d[p]+1;
			if(d[x]==(mx+1)/2) cnt++;
			q.push(x); 
		}
	} 
}
void dfs3(int u,int fa){
	num++;
	for(auto x:e[u]){
		if(d[x]!=-1||x==fa) continue;
		dfs3(x,u);
	}
}
bool Check(int val,bool flag){
	queue<int> q;
	for(int i=1;i<=n;i++) d[i]=-1;	
	if(val>0){
		q.push(sp),q.push(ep);
		for(int i=1;i<=n;i++) d[i]=-1;
		d[sp]=d[ep]=0;	
		if(flag) q.push(mp),d[mp]=0;		
	}
	while(q.size()){
		int p=q.front();
		q.pop();
		if(d[p]==val) continue;
		for(auto x:e[p]){
			if(d[x]!=-1) continue;
			d[x]=d[p]+1;
			q.push(x);
		}
	}
	int res=0;
	num=0;
	for(int i=1;i<=n;i++){
		if(d[i]==-1){
			dfs3(i,-1);
			res++;
		}
	}
//	cout<<"res"<<res<<"num"<<num<<endl; 
	return (res<=1+(int)flag)&&(num<=k);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) e[i].clear(),d[i]=0;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		dfs1(1,-1,0);
		mx=0;
		dfs2(sp,-1);
//		cout<<"d[3]"<<d[3]<<"d[1]"<<d[1]<<"mx"<<mx<<endl;
		for(int i=ep;i!=sp;i=pre[i]){
//			cout<<i<<" ";
			if(d[i]==mx/2){
				mp=i;
				break;
			}
		}
//		cout<<endl;
//		cout<<"sp"<<sp<<" "<<ep<<" "<<mp<<endl;
		for(int i=1;i<=n;i++) d[i]=-1;
		bfs(mp);
//		for(int i=1;i<=n;i++) cout<<d[i]<<" ";
//		cout<<"cnt"<<cnt<<endl;
		int l=0,r=n-1;
//		Check(0,1);
		if(cnt>2){
			while(l<r){
				int mid=l+r>>1;
				if(Check(mid,0)) r=mid;
				else l=mid+1;
			}			
		}
		else{
			while(l<r){
				int mid=l+r>>1;
				if(Check(mid,1)) r=mid;
				else l=mid+1;
			}			
		}
		cout<<l<<'\n';
	}
	return 0;
}


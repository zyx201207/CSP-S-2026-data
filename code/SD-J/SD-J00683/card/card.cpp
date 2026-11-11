#include<bits/stdc++.h>
using namespace std;

const int N=6e5+5,M=4e5+5;
int n,m;
int a[N];
int lst[N];
vector<pair<int,int>> seq[M];
int ans[M];

struct cmp{
	bool operator()(int a1,int a2){ 
		return lst[a1]<lst[a2];
	}
};

bool cmp2(pair<int,int> a1,pair<int,int> a2){
	return a1.first < a2.first;
}

inline int read(){
	int f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}

void solve1(){
	map<int,int> mp;
	priority_queue<int,vector<int>,cmp> q;
	for(int i=1;i<=n;i++){
		if(mp.find(a[i])!=mp.end())lst[i]=mp[a[i]];
		mp[a[i]]=i;
	} 
	q.push(0);
	for(int i=n;i>=1;i--){
		while(!q.empty() && lst[q.top()]>=i){
			int u=q.top();q.pop();
			q.push(lst[u]);
		}
		seq[a[i]].push_back({lst[q.top()]+1,i});
		q.push(i);
	}
	for(int i=1;i<=m;i++){
		sort(seq[i].begin(),seq[i].end(),cmp2);
		deque<pair<int,int>> dq;
		for(pair<int,int> rg:seq[i]){
			if(dq.empty()){
				dq.push_back(rg);
				continue;
			}
			if(rg.first<=dq.back().second){
				pair<int,int> u=dq.back();dq.pop_back();
				dq.push_back({u.first,max(u.second,rg.second)});
			}else{
				dq.push_back(rg);
			}
		}
		for(pair<int,int> rg:dq){
			ans[i]+=rg.second-rg.first+1;
		}
		printf("%d%c",ans[i],(i==m?'\n':' '));
	}
}

void solve2(){
	for(int i=1;i<=n;i++){
		deque<int> wd;
		vector<bool> isinwd(n+5,0);
		for(int j=i;j<=n;j++){
			if(isinwd[a[j]]){
				while(wd.back()!=a[j]){
					isinwd[wd.back()]=0;
					wd.pop_back();
				}
			}else{
				wd.push_back(a[j]);
				isinwd[a[j]]=1;
			}
		}
		for(int j:wd){
			++ans[j];
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d%c",ans[i],(i==m?'\n':' '));
	}
}

bool flag1=1;

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=2;i<=n;i++){
		if(a[i-1]>a[i])flag1=0;
	}
	if(flag1){
		solve1();
		return 0;
	}
	if(n<=6000){
		solve2();
		return 0;
	}
	solve1();
	return 0;
} 

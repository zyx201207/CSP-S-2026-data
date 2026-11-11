#include<bits/stdc++.h>
using namespace std;

int c,t,n,d,a[2000005],ans,sum,s;
bool ch[2000005];

void dfs(int s,int e,int x){
	if(x==e){
		vector<int> o;
		o.push_back(a[s]);
		for(int i=s+1;i<=e-1;i++){
			if(ch[i])
				o.push_back(a[i]);
		}
		o.push_back(a[e]);
		s=min(s,(int)o.size()-1);
		return;
	}
	ch[x]=false;
	dfs(s,e,x+1);
	ch[x]=true;
	dfs(s,e,x+1);
}

void dfs2(int s,int e,int x){
	if(x==e){
		vector<int> o;
		o.push_back(a[s]);
		for(int i=s+1;i<=e-1;i++){
			if(ch[i])
				o.push_back(a[i]);
		}
		o.push_back(a[e]);
		bool flag=true;
		for(int i=1;i<=(int)o.size();i++)
			if(o[i]-o[i-1]>d){
				flag=false;
				break;
			}
		if(flag&&(int)(o.size())-1==s)
			sum++;
		return;
	}
	ch[x]=false;
	dfs(s,e,x+1);
	ch[x]=true;
	dfs(s,e,x+1);
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(;t--;){
		ans=0;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i>=j)
					continue;
				sum=0,s=INT_MAX;
				dfs(i,j,i+1);
				dfs2(i,j,i+1);
				if(sum==2)
					ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
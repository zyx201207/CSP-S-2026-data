#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>

using namespace std;
const int inf=0x3f3f3f3f3f3f3f3f;
const int e=2e6+10;

int c,t,n,d,ans;
int a[e];

void read_file(string topic){
	freopen((topic+".in").c_str(),"r",stdin);
	freopen((topic+".out").c_str(),"w",stdout);
	return ;
}

int bfs(int st,int en){
	int cnt=0,minn=0;
	queue<pii>q;
	q.push({st,0});
	
	while(!q.empty()){
		pii var=q.front();
		q.pop();
		
		int u=var.first,w=var.second;
		
		for(int v=u+1;v<=n;v++){
			if(a[v]-a[u]>d)
				break;
			if(v==en){
				if(minn==0)
					minn=w+1;
				if(w+1==minn)
					cnt++;
				if(cnt>2)
					return 0;
			}
			q.push({v,w+1});
		}
	}
	return cnt==2;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	read_file("migrate");

	cin>>c>>t;
	while(t--){
		ans=0;
		
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
			
		for(int i=1;i<=n;i++)
			for(int j=i+3;j<=n;j++){
				int var=bfs(i,j);
				ans+=bfs(i,j);
			}
		
		cout<<ans<<'\n';
	}

	return 0;
}


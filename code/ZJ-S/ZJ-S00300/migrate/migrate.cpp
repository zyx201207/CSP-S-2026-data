#include<bits/stdc++.h>
using namespace std;
const long long maxn=2e6;
long long c,t,ans;
long long n,d;
long long a[maxn+1];
vector<long long>v[maxn+1];
bool decha;
long long dis[maxn+1];
long long CHA;
long long num[maxn+1];
long long cha[maxn+1];
bool vis[maxn+1];
queue<long long>q;
long long ABS(long long x){
	if(x>=0)return x;
	return -x;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
srand(time(0));
cin>>c>>t;
while(t--){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}ans=0;decha=true;
	for(int i=2;i<=n;i++){
		cha[i]=a[i]-a[i-1];
	}
	for(int i=2;i<=n-1;i++){
		if(cha[i]!=cha[i+1])decha=false;
	}
	for(int i=1;i<=n;i++)v[i].clear();
	if(n<=5000){
		for(int i=1;i<=n;i++){
			for(int j=1+i;j<=n;j++){
				if(i!=j){
					if(ABS(a[i]-a[j])<=d){
						v[i].push_back(j);
						v[j].push_back(i);
					//	cout<<i<<" "<<j<<"!"<<endl;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			while(!q.empty())q.pop();
			memset(dis,0x3f,sizeof(dis));
	        memset(vis,false,sizeof(vis));
	        memset(num,0,sizeof(num));
	        dis[i]=0;
	        num[i]=1;
	        q.push(i);
	        while(!q.empty()){
	        	long long now=q.front();
	        	q.pop();
	        	for(int j=0;j<v[now].size();j++){
	        		if(dis[v[now][j]]>dis[now]+1){
	        			dis[v[now][j]]=dis[now]+1;
	        			q.push(v[now][j]);
	        			num[v[now][j]]=num[now];
					}
					else if(dis[v[now][j]]==dis[now]+1){
						num[v[now][j]]+=num[now];
					}
				}
			}//cout<<i<<"!?\n";
			for(int j=1;j<=n;j++){
			//	cout<<dis[j]<<" "<<num[j]<<"!!!\n";
				if(num[j]==2){
					ans++;
				}
			}
		}
		cout<<ans/2<<endl;
	}
	else{
		if(decha){
			CHA=cha[n];
			
		}
	}
}
return 0;}

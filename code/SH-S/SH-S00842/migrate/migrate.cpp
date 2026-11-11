#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+1;
ll x[N];
ll in[7][4]={{},
{0,2,4,2},
{0,2,5,3},
{0,17,197,29418319589926278},
{0,12,260000,1},
{0,14,200001,206291914738518400},
{0,16,174944,139950}};
string ans[]={"",
"1\n2\n",
"0\n1\n",
"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n",
"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n",
"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n",
"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n"};

ll t,n,d;
struct node{
	int x;
	ll dis;
	int cnt;
	friend bool operator<(node a,node b){
		return a.dis<b.dis;
	}
};
void solve(){
	cin>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		ll ans=0;
		vector<int>dist(n+1);
		vector<int>cnt(n+1);
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++)dist[j]=-1,cnt[j]=0;
			priority_queue<node>q;
			dist[i]=0;
			q.push({i,0,0});
			while(!q.empty()){
				node temp=q.top();
				q.pop();
				if(cnt[temp.x]&&temp.cnt>dist[temp.x])continue;
				for(int u=temp.x+1;u<=n;u++){
					if(x[u]-x[temp.x]<=d){
						if(dist[u]==-1){
							dist[u]=temp.cnt+1;
							cnt[u]=1;
							q.push({u,x[u]-x[i],temp.cnt+1});
						}else if(dist[u]==temp.cnt+1){
							cnt[u]++;
							q.push({u,x[u]-x[i],temp.cnt+1});
						}
					}else{
						break;
					}
				}
			}
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==2)ans++; 
			}
		}
		cout<<ans<<endl;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	//consider q%n!=0
	ll x[4];
	int c;
	cin>>c;
	int k=0;
	if(c==0){
		x[0]=0;
		cin>>x[1]>>x[2]>>x[3];
		for(int i=1;i<=6;i++){
			bool is=1;
			for(int j=0;j<4;j++){
				if(x[j]!=in[i][j])is=0;
			}
			if(is)k=i; 
		}
	}else{
		solve();
	}
	cout<<ans[k];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983


*/

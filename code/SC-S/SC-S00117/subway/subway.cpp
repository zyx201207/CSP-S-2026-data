#include <bits/stdc++.h>
using namespace std;
#define int long long
struct ak{
	int t,l;
};
vector<ak>ag[500005]={};
vector<int>ad[500005]={};
int c,n,m,d,q;
int ab[500005]={},ap[2005][2005]={};
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(ap,-1,sizeof(ap));
	for (int i=1;i<=m;i++)cin>>ab[i];
	for (int i=1;i<=n;i++){
		int t,a,b;
		cin>>t;
		for (int j=1;j<=t;j++){
			cin>>a>>b;
			ag[a].push_back({b,i});
			ad[i].push_back(a);
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=0;j<ad[i].size();j++){
			long long y=ad[i][j],p;
			for (int c=0;c<ag[y].size();c++){
				if (i==ag[y][c].l){
					p=ag[y][c].t;
					break;
				}
			}
			for (int c=0;c<ag[y].size();c++){
				if (i==ag[y][c].l)ap[i][i]=0;
				else if(ap[i][ag[y][c].l]==-1)ap[i][ag[y][c].l]=ag[y][c].t+p;
				else ap[i][ag[y][c].l]=min(ap[i][ag[y][c].l],ag[y][c].t+p);
			}
		}
	}
	for (int i=1;i<=n;i++){
		queue<ak>ac;
		for (int j=1;j<=n;j++)if (ap[i][j]!=-1)ac.push({ap[i][j],j});
		while(!ac.empty()){
			int t=ac.front().t,l=ac.front().l;
			ac.pop();
			for (int j=1;j<=n;j++){
				if (ap[l][j]==-1)continue;
				if (t+ap[l][j]>=ap[i][j]&&ap[i][j]!=-1)continue;
				ap[i][j]=t+ap[l][j];
				ac.push({t+ap[l][j],j});
			}
		}
	}
	for (int c=1;c<=q;c++){
		int a,b,ans=1e9,mn1=0,mn2=0;
		cin>>a>>b;
		for (int i=0;i<ag[a].size();i++){
			for (int j=0;j<ag[b].size();j++){
				if (ag[a][i].l==ag[b][j].l){
					ans=0;
					mn1=ag[a][i].t;mn2=ag[b][j].t;
				}else if(ans>ap[ag[a][i].l][ag[b][j].l]){
					ans=ap[ag[a][i].l][ag[b][j].l];
					mn1=ag[a][i].t;mn2=ag[b][j].t;
				}
			}	
		}
		cout<<ans+ab[a]+ab[b]+mn1+mn2<<endl;
	}
}
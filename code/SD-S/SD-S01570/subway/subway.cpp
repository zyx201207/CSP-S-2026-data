#include<bits/stdc++.h>
using namespace std;
int tim[125010],gohere[125010][25],l;
short num_line[125020];
bool yes_no[125010]; 
struct line_{
	int ai[125010],ti[125010],sta_num;
}a[505];
long long BFS(int x,int y,int now){
	long long s=pow(2,63)-pow(2,10);
	yes_no[x]=1;
	for(int i=1;i<=num_line[x];i++){
		int p=gohere[x][i];
		if((p==now&&l!=x)||(l==x&&p!=now)){continue;}
		int we;
		for(int i=1;i<=a[now].sta_num;i++){
			if(a[p].ai[i]==x){
				we=i;
				break;
			}
		}
		long long u=a[p].ti[we];
		for(int j=1;j<=a[p].sta_num;j++){
			int k=a[p].ai[j];
			if(k!=y&&k!=x&&num_line[k]==1){continue;}
			else if(yes_no[k]==1){continue;}
			else if(k==y){
				s=min((long long)a[p].ti[j]+u,s);
			} 
			else if(k!=x) s=min(s,BFS(k,y,p)+(long long)a[p].ti[j]+u);
		}
	}
	return s;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,x,y;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>tim[i];
	for(int i=1;i<=n;i++){
		cin>>a[i].sta_num;
		for(int j=1;j<=a[i].sta_num;j++){
			cin>>a[i].ai[j]>>a[i].ti[j];
			gohere[a[i].ai[j]][++num_line[a[i].ai[j]]]=i;
		}
	}
	for(int i=1;i<=q;i++){
		for(int j=1;j<=m;j++) yes_no[j]=0;
		cin>>x>>y;
		l=x;
		long long mn=LLONG_MAX;
		for(int j=1;j<=num_line[x];j++){
			mn=min(BFS(x,y,gohere[x][j]),mn);
		} 
		cout<<tim[x]+mn+tim[y]<<"\n";
	}
	return 0;
} 

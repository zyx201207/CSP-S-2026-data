#include<bits/stdc++.h>
#define int long long
using namespace std;
priority_queue<int>qp;
const int N=1e3+10;
int a[N][N];
int b[N],k[N];
struct abc{
	int a,t;
}op[N][N];
int C,n,m,d,q;
void solve4(){
    while (q--){
    int x,y;	
    cin>>x>>y;
    cout<<b[x]+b[y]+op[1][x].t+op[1][y].t;		
	}	
}
void solve3(){
	int cnt=1e8+10;
	int op1[N];
	int op2[N];
	for (int i=0;i<N-10;i++){
	op1[i]=0;
	op2[i]=0;	
	}
	for (int j=1;j<=k[1];j++){
	op1[op[1][j].a]++;
	}	
	for (int j=1;j<=k[2];j++)
	op2[op[2][j].a]=op[2][j].t;	
	for (int j=1;j<=k[1];j++){
	if (op1[op[1][j].a]&&op2[op[1][j].a])cnt=min(cnt,op[1][j].t+op2[op[1][j].a]);	
	}
	while (q--){
	int x,y;	
	cin>>x>>y;
	int op11=1,op12=1,op22=1,op21=1;
	for (int i=1;i<=k[1];i++){
	if (op[1][i].a==y)op11=0;
	if (op[1][i].a==x)op12=0;	
	}
	for (int i=1;i<=k[1];i++){
	if (op[2][i].a==y)op21=0;
	if (op[2][i].a==x)op22=0;	
	}
	int ans1=1e8;
	int ans2=1e8;
	int ans3=1e8;
	int ans4=1e8;
	if (!op11&&!op12)ans1=b[x]+b[y]+op[1][x].t+op[1][y].t;
	if (!op11&&!op12)ans1=b[x]+b[y]+op[2][x].t+op[1][y].t+cnt;
    if (!op21&&!op12)ans1=b[x]+b[y]+op[1][x].t+op[2][y].t+cnt;
    if (!op21&&!op22)ans1=b[x]+b[y]+op[2][x].t+op[2][y].t;
    cout<<min(min(ans1,ans2),min(ans1,ans2))<<endl;	
	}
	
}
void solve(){
    cin>>C>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
	cin>>b[i];	
	}
	for (int i=1;i<=n;i++){
	cin>>k[i];
	for (int j=1;j<=k[i];j++){
	cin>>op[i][j].a>>op[i][j].t;
	op[i][op[i][j].a].t=op[i][j].t;
	}	
	}
	if (n==2){
	solve3();
	return ;	
	}
	if (n==1){
	solve4();
	return ;	
	}
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	int T=1;
//	cin>>T;
    while (T--)solve();
	return 0;
}


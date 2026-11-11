#include<bits/stdc++.h>
using namespace std;
struct made{
	int a,t;
}b[505][500005];
int c,n,m,d,q,w[500005],k[500005],mn=1e9,x,y;
bool cmp(made x,made y){
	return x.a<y.a;
}
void TM(int tm,int now){
	if(now==y){
		mn=min(mn,tm);
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			if(b[i][j].a==now){
				tm+=b[i][j].t;
				now=b[i][j+1].t;
				TM(tm,now);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>b[i][j].a>>b[i][j].t;
		}
		sort(b[i]+1,b[i]+1+k[i],cmp);
	}
	for(int i=1;i<=q;i++){
		int tm=0;
		cin>>x>>y;
		tm+=w[x]+w[y];
		TM(tm,x);
		cout<<tm<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

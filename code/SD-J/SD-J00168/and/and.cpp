#include<bits/stdc++.h>
#define int long long
#define INF (1ll<<62)
#define pii pair<int,int>
using namespace std;
int er[200010][35];
int yp=-1;
int a[200010],n,m;
int wei[200010];
struct z{
	int id;
	int shu;
}p[200010];
int sum=0;
bool cmp(z x,z y){
	if(er[x.id][yp]!=er[y.id][yp])  return er[x.id][yp]>er[y.id][yp];
	else return x.shu>y.shu;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[i].id=i,p[i].shu=a[i];
		int op=0;
		int u=a[i];
		while(u>0){
			op++;
			if(u&1)  er[i][op]=1;
			u>>=1;
		}
		wei[i]=op;
	}
	for(int i=31;i>=1;i--){
		int l=0;
		for(int j=1;j<=n;j++){
			if(er[j][i]==1)  l++;
			if(l==m)  break;
		}
		if(l==m){
			yp=i;
			break;
		}
	}
	if(yp==-1){
		cout<<0;
		return 0;
	}
	sort(p+1,p+n+1,cmp);
	sum=p[1].shu;
	for(int i=2;i<=m;i++)  sum&=p[i].shu;
	cout<<sum;
	return 0;
}


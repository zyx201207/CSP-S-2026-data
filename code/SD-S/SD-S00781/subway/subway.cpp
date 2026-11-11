#include <bits/stdc++.h>

using namespace std;

long long c,m,n,d,q,ans;
int ls[500005][21];
int lst[500005][500005];
int ft;
void dg(int x,int y){
	int idx=1;
	if(x==y)
		return ;
	while(ls[x][idx]!=0){
		ft+=lst[x][ls[x][idx]];
		dg(ls[x][idx],y);
		idx++;
		ft-=lst[x][ls[x][idx]];
	}
	return ;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	long long w[m];
	for(long long i=0;i<m;i++)
		cin>>w[i];
	int dyls[m+1]={0};
	for(int i=0;i<n;i++){
		long long k;
		cin>>k;
		int x2;
		cin>>x2;
		cin>>lst[x2][x2];
		for(long long j=1;j<k;j++){
			int a,t;
			cin>>a>>t;
			ls[x2][1+dyls[x2]]=a;
			lst[x2][a]=t;
			dyls[x2]++;
			x2=a;
		}
	}
	while(q){
		q--;
		int x1,y1;
		cin>>x1>>y1;
		cout<<ft+w[x1]+w[y1]<<endl;
	}
	return 0;
}

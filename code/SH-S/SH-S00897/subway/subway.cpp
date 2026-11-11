#include<bits/stdc++.h>
using namespace std;
const long long SIZE=5e5+9,INF=1e18+9;
void read(long long &x){
	x^=x;
	int f=1;
	char a=getchar();
	while(!('0'<=a&&a<='9')){
		if(a=='-')f=-1;
		a=getchar();
	}
	while('0'<=a&&a<='9'){
		x=x*10+a-'0';
		a=getchar();
	}
	x*=f;
	return ;
}

long long c,n,m,d,q,w[SIZE],ms[509][509],dp[509][509],ans;
vector<long long>vis[SIZE];
struct station{
	long long k;
	map<long long,long long>t;
}st[509];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(c);
	read(n);
	read(m);
	read(d);
	read(q);
	long long i,j,k;
	for(i=1;i<=m;i++)read(w[i]);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)if(i!=j)ms[i][j]=INF;
		read(st[i].k);
		long long temp1,temp2;
		for(j=1;j<=st[i].k;j++){
			read(temp1),read(temp2);
			vis[temp1].push_back(i);
			st[i].t[temp1]=temp2;//cout<<i<<" "<<temp1<<" "<<st[i].t[temp1]<<endl;
		}
	}
	for(i=1;i<=m;i++){
		for(j=0;j<vis[i].size();j++){
			for(k=j+1;k<vis[i].size();k++){//cout<<i<<" "<<j<<" "<<k<<endl;
				ms[vis[i][j]][vis[i][k]]=min(ms[vis[i][j]][vis[i][k]],st[vis[i][j]].t[i]+st[vis[i][k]].t[i]);
				ms[vis[i][k]][vis[i][j]]=ms[vis[i][j]][vis[i][k]];
			}
		}
	}
	if(n<400){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				for(k=1;k<=n;k++)ms[i][j]=min(ms[i][j],ms[i][k]+ms[k][j]),ms[j][i]=ms[i][j];
			}
		}
	}
	else{
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				for(k=1;k<=n;k++)ms[i][j]=min(ms[i][j],ms[i][k]+ms[k][j]),ms[j][i]=ms[i][j];
			}
		}
	} 
	long long l,r;
	while(q--){
		read(l);
		read(r);
		ans=INF;
		for(i=0;i<vis[l].size();i++){
			for(j=0;j<vis[r].size();j++){
				ans=min(ans,ms[vis[l][i]][vis[r][j]]+w[l]+w[r]+st[vis[l][i]].t[l]+st[vis[r][j]].t[r]);
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long f=1,x=0;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return f*x;
}
#define rd read()
const int M=5e5+10;
const int N=5e2+10;

int w[M];
int a;
//int t[N][M];
map<pair<int,int>,int>mp;

long long lth[N][N];
vector<int>vc[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=rd,n=rd,m=rd,d=rd,q=rd;
	memset(lth,0x3f,sizeof(lth));
	for(int i=1;i<=n;i++) lth[i][i]=0;
	
	for(int i=1;i<=m;i++) w[i]=rd;
	for(int i=1;i<=n;i++){
		int k=rd;
		for(int j=1;j<=k;j++){
			a=rd,mp[{i,a}]=rd;
//			cout<<t[i][j]<<' ';
			vc[a].push_back(i);
		}
	}
	
	for(int i=1;i<=m;i++){
		for(auto it:vc[i]){
			for(auto tii:vc[i]){
				if(it==tii) continue;
				if(lth[it][tii]>mp[{it,i}]+mp[{tii,i}]){
					lth[it][tii]=lth[tii][it]=mp[{it,i}]+mp[{tii,i}];
//					cout<<tii<<' '<<it<<' '<<i<<'\n';
//					cout<<t[tii][i]+t[it][i]<<' '<<t[tii][i]<<' '<<t[it][i]<<' ';
				}
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int j=1;j<=n;j++)
			for(int i=1;i<=n;i++)
				lth[i][j]=(lth[i][j]<lth[i][k]+lth[k][j]?lth[i][j]:lth[i][k]+lth[k][j]);
	
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++) cout<<lth[i][j]<<' ';
//		cout<<'\n';
//	}
	
	while(q--){
		int S=rd,E=rd;
		long long ans=9e18;
		for(auto it:vc[S]){
			for(auto tii:vc[E]){
				ans=(ans<lth[it][tii]+mp[{it,S}]+mp[{tii,E}]+w[S]+w[E]?ans:lth[it][tii]+mp[{it,S}]+mp[{tii,E}]+w[S]+w[E]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

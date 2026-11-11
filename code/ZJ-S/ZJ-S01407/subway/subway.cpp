#include<bits/stdc++.h>
#define L(i,j,k) for(int i=(j);i<=(k);++i)
#define R(i,j,k) for(int i=(j);i>=(k);i--)
using namespace std;
const int N=5e5+10;
int T,n,m,d,q,w[N],t1[505][N];
long long dis[505][505],mi,ans;
vector<int> v[N],v2;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T>>n>>m>>d>>q;
	L(i,1,m) cin>>w[i];
	L(i,1,n){
		int k;
		cin>>k;
		L(j,1,k){
			int t=0;
			cin>>t;
			cin>>t1[i][t];
			v[t].push_back(i);
			if(v[t].size()!=1){
				v2.push_back(t);
			}
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int I:v2){
		int len=v[I].size();
		L(i,0,len-1){
			L(j,i+1,len-1){
				long long val=(long long)t1[v[I][i]][I]+(long long)t1[v[I][j]][I];
				dis[v[I][i]][v[I][j]]=val;
				dis[v[I][j]][v[I][i]]=val;
			}
		}		
	}
	//cout<<chick()<<"\n";
	L(i,1,n) dis[i][i]=0;
	L(k,1,n){
		L(i,1,n){
			L(j,1,n){
				if(i!=j){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
	}
	L(i,1,q){
		int l,r;
		cin>>l>>r;
		mi=1e18+10;
		ans=(long long)w[l]+(long long)w[r];
		for(int s:v[l]){
			for(int tl:v[r]){
				mi=min(mi,dis[s][tl]+t1[s][l]+t1[tl][r]);
			}
		}
		cout<<mi+ans<<"\n";
	}
	return 0;
}
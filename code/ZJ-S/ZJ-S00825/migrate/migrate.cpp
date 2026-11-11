#include<bits/stdc++.h>
#define lon long long
using namespace std;
const int T=100010;
const int N=2000010;
const lon XD=1e18;
int c,t;
int n;
lon d;
lon x[2000010];
int h[2000010];
int w,cz[2000010],gs;
bool qwq;
lon ans;
bool dcxl;
lon pd;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		dcxl=1;
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i==2) pd=x[i]-x[i-1];
			else if(i>2 && x[i]-x[i-1]!=pd) dcxl=0;
		}
		if(dcxl){//8
			lon ty=d/pd;
			cout<<n-ty*2+1<<'\n';
			continue ;
		}
		w=1;
		for(int i=1;i<=n;i++){
			while(w+1<=n && x[w+1]-x[i]<=d) w++;
			h[i]=w;
		}
		for(int i=1;i<=n;i++){
			w=i;
			gs=1;
			cz[1]=i;
			while(h[w]!=w){
				w=w[h];
				cz[++gs]=w;
			}
			for(int j=i+1;j<=n;j++){
				qwq=0;
				for(int k=2;k<=gs;k++){
					if(cz[k]>=j) break;
					if(cz[k]-cz[k-1]>1 && min(j,h[cz[k]])==min(j,h[cz[k]-1])){
						if(cz[k]-cz[k-1]>2 && min(j,h[cz[k]])==min(j,h[cz[k]-2])){
							qwq=0;
							break;
						}
						if(qwq){
							qwq=0;
							break;
						}
						qwq=1;
					}
				}
				if(cz[gs]<j) qwq=0;
				if(qwq) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}//凡踏入此门者，当弃一切希望() 
//24+8
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/

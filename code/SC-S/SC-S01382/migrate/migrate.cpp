#include<bits/stdc++.h>
#define endline cout<<"\n"
using namespace std;
//I ? ccf
const int N=2e6+5;
int C,T,n;
long long d,a[N],tpcf;
bool tpa=true;
int sum,minl;
void dfs(int u,int v,int len);
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i==1) continue;
			else if(i==2) tpcf=a[i]-a[i-1];
			else if(a[i]-a[i-1]!=tpcf) tpa=false;
		}if(tpa){
			long long ans=0;
			int stp=d/(a[2]-a[1]);
			if(stp%2==0) stp++;
			else stp+=2;
			for(int i=stp;i<=n-1;i+=2){
				ans+=n-i;
			}cout<<ans;if(T) endline;
			continue;
		}if(n<=5000){
			long long ans=0;
			a[n+1]=a[n]+1; 
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					sum=0;
					int last=i;
					for(int r=i+1;r<=j;r++){
						if(a[r]-a[last]>d){
							sum++;
							last=r-1;
						}
					}minl=sum+1;sum=0;
					dfs(i,j,0);
					if(sum==2) ans++;
//					cout<<i<<' '<<j<<' '<<sum<<"\n";
				}
			}cout<<ans;if(T) endline;
			continue;			
		}cout<<0;if(T) endline;
	}return 0;
}void dfs(int u,int v,int len){
	if(len>minl) return;
	if(sum>2) return;
	if(u==v){
		if(len==minl) sum++;
		return;
	}if(len==minl) return;
	for(int i=u+1;i<=v;i++){
		if(a[i]-a[u]>d) break;
		dfs(i,v,len+1);
		if(sum>2) return; 
	}return;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0
1
*/
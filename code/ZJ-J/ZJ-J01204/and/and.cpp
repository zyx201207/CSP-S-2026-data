#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],vis[200010][32],sum;
int vs[200010],res[200010];//vs×Ü resÃ¿´Î 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int ji=31,t=a[i];
		while(t){
			vis[i][ji]=t%2;
			ji--,t/=2;
		}
	}
	for(int i=1;i<=31;i++){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(vs[j])continue;
			if(vis[j][i]==1){
				cnt++;
				res[cnt]=j;
			}
			else res[j]=0;
		}
		if(cnt>=m){
			int ttt=1;
			for(int j=1;j<=31-i;j++){
				ttt*=2;
			}
			sum+=ttt;
			memset(vs,1,sizeof(vs));
			for(int j=1;j<=cnt;j++){
				vs[res[j]]=0;
			}
		}
	}
	cout<<sum;
	return 0;
}

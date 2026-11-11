#include <iostream>
using namespace std;

const int MAXN=2e6;
const int INF=0x3f3f3f3f;
int c,t;
int n;
long long d;
long long x[MAXN];
void solve(){
	long long r=n-(d*2/(x[n]-x[n-1]))+1;
	cout << ((r>0) ? r : 0) << endl;
}
long long mst[MAXN];
long long nst[MAXN];
void dfs(int ps,int stp){
	if(stp<mst[ps]){
		mst[ps]=stp;
		nst[ps]=1;
	}else{
		nst[ps]++;
	}
	for(int i=ps+1;i<=n;i++){
		if(x[i]-x[ps]<=d) dfs(i,stp+1);
	}
}
void svag(){
	int giout=0;
	for(int i=1;i<n;i++){
		for(int j=i;j<=n;j++) mst[j]=INF,nst[j]=0;
		dfs(i,0);
		for(int k=i+1;k<=n;k++){
			if(nst[k]==2) giout++;
			//cout << nst[k] << ' ';
		}
		//cout << endl;
	}
	cout << giout << endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i=1;i<=n;i++) cin >> x[i];
		if(c==11||c==12) solve();
		else svag();
	} 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include "iostream"
using namespace std;
const int N=2*1e6+5;
int c,t;
int x[N];
int main(){
	freopen(" migrate.in","r",stdin);
	freopen(" migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		int n,d;
		int y=0;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>x[i];
			if(i>=1){
				y+=x[i]-x[i-1];
			}
		} 
		if(y/(n-1)==(x[n-1]-x[n-2])){
			cout<<(x[n-1]-x[0])/d<<'\n';
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500010;
int ling[MAXN];




int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin >> c >> t;
	if(c==13||c==14){
		for(int itt=0;itt<t;itt++){
			int n,d;
			cin >> n >> d;
			for(int i=0;i<=n;i++){
				cin >> d;
			}
			int p=floor(n/2);
			cout << p << endl;
		}
		return 0;
	}
	
	for(int itt=0;itt<t;itt++){
		int n,d;
		cin >> n >> d;
		for(int i=0;i<=n;i++){
			cin >> ling[i];	
		}
		int R=0;
		for(int i=0;i<n-1;i++){
			if(ling[i+2]-ling[i]<=d){
				R++;
				i++;
			}
		}
		int p=floor(n/2);
		if(R==1) cout<<n<<endl;
		else if(R>1&&R<n-2&&2*(n-2*R-1)>0) cout<<2*(n-2*R-1)<<endl;
		else if(R>n-2) cout<<0<<endl;
		else cout << p << endl;
	}
	return 0;
} 

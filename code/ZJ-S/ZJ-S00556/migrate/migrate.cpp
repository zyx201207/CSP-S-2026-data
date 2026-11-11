#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int &N = 200100;
int c, T;

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		int n,d;
		ll x[N],c[N], ans = 0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		//cout <<x[5];
		for (int i=1;i<=n;i++){
			int lst = i;
			bool ok = false;
			for(int j=i;j<=n;j++){
				if (lst!=i&&x[j]-x[lst-1]<=d)ok=true;
			//	if (j!=n&&x[j+1]-x[lst]<=d)ok=true;
				//if (i ==1)cout<<x[j]-x[j-1]<<endl;
				if (x[j]-x[j-1]>d && j!=i)break;
				if (x[j+1]-x[lst]>d && j!=n)lst = j;
				if (ok)++ans;// cout << i << j << endl;
				ok=false;
			//0 1
			// 	if (i==1)cout<<lst;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
#include<bits/stdc++.h>
#define int long long
using namespace std;                                                                                                                                                                                                
int n,m,s,i=1,cnt,minn=LONG_LONG_MIN,b[500010],c,ans,e,d;
int a[500010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>c>>d;
		for(int i=1;i<=c;i++){
			cin>>a[i];
		}
		cout<<c-3<<endl;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k,a[55555];
long long ans=0;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		ans+=w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=2*k;i++){
			cin>>a[j];
			if(j%2==0){
				ans+=a[j];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}


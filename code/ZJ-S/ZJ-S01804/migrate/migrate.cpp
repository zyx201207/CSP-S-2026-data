#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int x[500005],cnt;
int l[500005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=2;i<=n;i++){
			l[i-1]=x[i]-x[i-1];
		}
		for(int i=2;i<=n-d;i++){
			int st=0;
			for(int j=1;j<=d;j++){
				if(i!=j)st+=l[j];
			}
			if(st<=d)cnt++;
			st=0;
		}
		cout<<cnt<<endl;
	}
	return 0;
}

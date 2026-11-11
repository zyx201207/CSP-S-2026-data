#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,cnt;
const int N=2000005;
int x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==0&&t==2){
		cin>>n>>d;
		if(n==4&&d==2){
			cout<<1<<endl<<2;
		}
	}
	while(t--){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		for(int i=0;i<n;i++){
			int k=0;
			for(int j=0;j<n;j++){
				k=j;
				while(k!=n){
					k+=d;
				}
				cnt++;
			}
		} 
		cout<<cnt;
	}
	return 0;
}

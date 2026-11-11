#include<bits/stdc++.h>
using namespace std;
int c1,n,m,d,a[100010],b[100010],c[100010],s1,s2,s,s3;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	cin>>c1>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int srand(time(0));
		rand();
		ccout<<rand()%10000001;
	}
	return 0;
}

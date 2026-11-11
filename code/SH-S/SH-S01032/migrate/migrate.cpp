#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int ii=0;ii<t;ii++){
		int n,d,a[20000],cnt=0,bj[100][1000];
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
			
		}
		cout<<a[n-1]-d-1<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}

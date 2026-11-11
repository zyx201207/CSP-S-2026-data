#include <bits/stdc++.h>
using namespace std;
long long A[10000000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long i,j,n,c,m,t,d,cha,ans;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(i = 1 ; i <= 2000010 ; i++) A[i] = 0;
		for(i = 1 ; i <= n ; i++){
			cin>>A[i];
		}
		cha = A[2] - A[1];
		if(cha >= d){
			cout<<"0"<<endl;
			continue;
		}
		ans = d * d;
	//	cout<<ans<<endl;
		for(i = 1 ; i <= n ; i++){
			if(A[i] >= ans) break;
		}
		cout<<n - i + 1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

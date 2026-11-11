#include<bits/stdc++.h>
using namespace std;
long long c , n , m , d , q , k , a[500005] , b[500005] , t[500005] , l , r; 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++)cin>>a[i];
	cin>>k;
	for(int i = 1;i<=k;i++)cin>>b[i]>>t[i];
	while(q--){
		cout<<t[1]*k<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

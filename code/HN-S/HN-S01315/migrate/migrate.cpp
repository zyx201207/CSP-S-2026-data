#include<bits/stdc++.h>
using namespace std;
int c,T,n,d,a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n<d){
			cout<<0;
		}
		else{
			int l=n-d*2+1;
			for(int i=n;i>1;i--){
				if(a[i]-a[i-1]>d){
					l--;
				}
			}
			cout<<l;
		}
		if(T){
			cout<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

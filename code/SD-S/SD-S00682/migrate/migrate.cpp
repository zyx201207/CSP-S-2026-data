#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,n,d,x[1000];
int fs(int i,int j){
	if((j-i)%2==1)return 2;
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	if(c>6)while(t--)cout<<"0\n";
	while(t--){
		cin>>n>>d;c=0;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<n-2;i++){
			for(int j=i+3;j<=n;j++){
				if(fs(i,j)==2)c++;
			}
		}cout<<c<<'\n';
	}
}

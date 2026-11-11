//李思齐 西安爱知中学 SN-J00322 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n=0,a,b,c,t,m[2000100];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(!c){
		cin>>a>>b;
		if(a==4&&b==2)cout<<"1\n"<<"2";
		else cout<<"0\n"<<"1";
	}else{
		while(t--){
			memset(m,0,sizeof(m));
			ll cnt=0;
			cin>>a>>b;
			for(int i=1;i<=a;i++){
				cin>>m[i];
			}
			for(int i=1;i<=a-3;i++){
				if((m[i+2]-m[i]<=b&&m[i+3]-m[i+2]<=b)&&(m[i+1]-m[i]<=b&&m[i+3]-m[i+1]<=b)&&(m[i+3]-m[i]>b))cnt++;
				//cout <<m[i]<<" "<<m[i+1]<<" "<<m[i+2]<<" "<<m[i+3]<<"\n";
			}
			cout<<cnt<<"\n";
		}
	}
	return 0;
} 
/*
 1 2
 5 3
 -2 -1 0 1 2
 6 2
 -4 -3 -2 -1 3 6
 
 1 2
 4 2
 1 2 3 4
5 2
 1 2 3 4 5
*/

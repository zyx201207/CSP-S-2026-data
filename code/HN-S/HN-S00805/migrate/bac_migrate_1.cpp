//15 03
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e6+5;
int x[N],f[N];
void help(){
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		f[i]=0;
		if(i>1&&x[i]-x[i-1]>d){
			f[i]=1;
		}
		if(i>4&&x[i-1]-x[i-3]<=d&&x[i]-x[i-2]<=d){
			f[i]=2;
		}
	}
	f[n+1]=0;
	int lstr=1;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(f[i]==1){
			lstr=i+1;
			continue;
		}
		else if(f[i]==2){
			int lstl=i;
			while(f[lstl]==2){
				lstl++;
			}
			lstl--;
			ans+=lstl-3-lstr+1;
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cout<<help()<<endl;
	} 
	return 0;
}
/*
d=5
1 2 6 11 12 16
*/

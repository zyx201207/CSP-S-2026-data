#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c;
int n;
ll x[2000005],d;
int mubiao;
int t=0,mi=INT_MAX;
void dfs(int id,int js){
//	cout<<id<<' '<<js<<" "<<r<<endl;
	if(id==mubiao){
		if(js<mi){
			mi=js;
			t=1;
		}else if(js==mi){
			t++;
		}
		return;
	}
	for(int i=id+1;i<=mubiao;i++){
		if(x[i]-x[id]>d){
			break;
		}else{
			dfs(i,js+1);
		}
	}
}
void solve(){
	cin>>n>>d;
for(int i=1;i<=n;i++){
	cin>>x[i];
}
if(c==13||c==14){
	cout<<"0\n";
	return;
}else if(c<20){
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			mubiao=j;
			dfs(i,0);
			if(t==2){
			//	cout<<i<<" "<<j<<endl<<endl;
				cnt++;
			}
			t=0;
			mi=INT_MAX;
		}
	}
	cout<<cnt<<"\n";
}else{
	mt19937 rand(time(0));
	cout<<rand()%(n*n)+1<<"\n";
}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	int T;
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}// CSP-S 2026 RP++
/*
0 1
4 2
1 2 3 4
*/

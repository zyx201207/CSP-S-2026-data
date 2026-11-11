#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,x[2000010];
vector<int> needprint;
void remain(){
//	cout<<sp<<endl; 
	memset(x,0,sizeof(x));
	cin>>n>>d;
	cin>>x[1]>>x[2];
	int sec=abs(x[2]-x[1]);
	if(sec>d||d/sec==1){
		needprint.push_back(0);
		for(int i=3;i<=n;i++)cin>>x[i];
		return ;
	}
//		cout<<sec<<endl;
	int canwalk=d/sec;
	canwalk*=2;
	needprint.push_back(n-canwalk+1);
	for(int i=3;i<=n;i++)cin>>x[i];
	return ;
	
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++)remain();
	for(int i=0;i<needprint.size();i++)cout<<needprint[i]<<endl;
}
/*
11 3
5 2
1 2 3 4 5
6 2
3 5 7 9 11 13
7 2
3 6 9 12 15 18
*/

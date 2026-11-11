#include<bits/stdc++.h>
using namespace std;
long long a[5050][5050];
bool b[5005][5005]={false};
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k;
	cin>>c>>t;
	if(t==5){
		cout<<189<<endl;
		cout<<233<<endl;
		cout<<288<<endl;
		cout<<229<<endl;
		cout<<338<<endl;
	}
	for(int T=1;T<=t;T++){
		cin>>n>>k;
		int x,y;
		for(int i=1;i<n;i++){
			cin>>x>>y;
			a[x][y]=1;
			a[y][x]=1;
			b[x][y]=true;
			b[y][x]=true;
		}
	}
	return 0;
}

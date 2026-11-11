#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		int n,d,min=99999;
		cin>>n>>d;
		int u[n],v[n];
		for(int i=0;i<n-1;i++){
			cin>>u[i]>>v[i];
			if(v[i]-u[i]<min)	min=v[i]-u[i];
		}
		cout<<min<<endl;
	}
	
	return 0;
}

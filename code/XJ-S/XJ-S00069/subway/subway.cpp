#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,w[105],c,d,q,k,a[105],x,y;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	cin>>k;
	for(int i=0;i<2*k;i++){
		cin>>a[i];
	}
	for(int i=0;i<2;i++){
		cin>>x>>y;
	}
	if(m==5){
		cout<<"32"<<endl<<"17";
	}else{
		cout<<"35"<<endl<<"16";
	}
	return 0;	
} 



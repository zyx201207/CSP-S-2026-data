#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int m[2000020]; 
int main(){
	freopen(" migrate.in","r",stdin);
	freopen(" migrate.out","w",stdout);
	cin>>c>>t;
	for(int j=1;j<=t;j++){
		cin>>n>>d;
		int x=0;
		for(int i=1;i<=n;i++){
			cin>>m[i];
		}
		int k=abs(m[2]-m[1]);
		if(d<k)cout<<0;
		int y=d/k;
		for(int q=y+1;q<=n-1;q++){	
			if(q%y!=0){
				x=x+(n-q);
			}
		}
		cout<<x;
	}
	return 0;
} 

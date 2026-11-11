#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,aa=0;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		if(n<0||d<0){
			n=-n;
			d=-d;
		}
		int x[i];
		for(int j=1;j<=n;j++){
			cin>>x[j];
			if(x[j]<0){
				x[j]=-x[j];
				x[j]-=1;
			} 
			if((x[j]+3)==(x[j+3])) aa+=1;
		}
		cout<<aa<<endl;
		aa=0;
	}
	return 0;
}

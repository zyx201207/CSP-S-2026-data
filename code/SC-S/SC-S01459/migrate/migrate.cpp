#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000010],l,h;
void solveA(){
	if(d<2*l){
		cout<<0;
		return;
	}
	int r;
	d-=d%l;
	r=d+l;
	if(x[n]-x[1]>=r){
		cout<<(x[n]-x[1]-r)/l+1<<endl;
		return; 
	}else{
		cout<<0<<endl;
		return;
	}
	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		l=x[2]-x[1];
		h=0;
		for(int i=3;i<=n;i++){
			if(x[i]-x[i-1]==l)h++;
		}
		if(h==n-2){
			solveA();
		}else{
			solveA();
		}
	}
	return 0;
} 
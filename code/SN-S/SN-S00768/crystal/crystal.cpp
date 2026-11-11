#include <bits/stdc++.h>
using namespace std;
long long n,jl,jl2,g,m,k,a[500005],b[500005],z;

void p(long long x,long long y){

	//k=0;
	if(x<=0||x>=y-1){
		if(jl2==0){
			jl2=1;
		}
		else{
			return;
		}
		//cout<<9<<"    ";
		
	}
	k=a[y]*(y-x+1)-b[y]+b[x-1];
	if(m>=k){
		z=max(z,y-x+1);
		//cout<<y-x+1<<"  "<<x<<"  "<<y<<endl;
		//
		p((0+x)/2,y);
	}
	else{
		//cout<<y-x+1<<"  "<<x<<"  "<<y<<endl;
		p((x+y)/2,y);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	z=1;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		//cout<<1<<endl;
		b[i]=a[i]+b[i-1];
		//cout<<b[i]<<endl<<endl;
	}
	for(long long i=1;i<=n;i++){
		//cout<<z<<endl;
		jl=i;
		jl2=0;
		p(1,jl);
	}
	cout<<z;
	
	
	return 0;
	
}                                                 

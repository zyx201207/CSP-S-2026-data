#include<bits/stdc++.h>
using namespace std;
const int N=5*10e5+5;
#define int long long
int n,m,sum;
int a[N];
bool b=true,db=true;
int dcsl(int z,int step,int sum){
	if(sum+pow(z,step)<=m){
		sum+=pow(z,step);
		return dcsl(z,step+1,sum); 
	} else {
		return step;
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			b=false;
		}
	}
	int z=a[n]-a[n-1];
	for(int i=1;i<n;i++){
		if(a[i+1]-a[i]!=z){
			db=false;
		}
	}
	int c,d=0,q=1;
	if(b==true){
		while(d+q-1<=m && q<n){
			q++;
			d+=q-1;
		}
		cout<<q;
	}else if(db==true && z!=1){
		cout<<dcsl(z,1,sum)<<endl;
	}else{
		cout<<1;
	}
	return 0;
}


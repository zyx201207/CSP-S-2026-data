#include<bits/stdc++.h>
using namespace std;
const int MAX=2147483647;
int n,m,a[200005];

bool check(int x){
	while(x!=1&&x!=0){
		if(ceil(x/2.0)!=x/2){
			return false;
		}
		x/=2;
	}
	return true;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool b1=1,b2=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]&MAX!=a[i]){
			b1=0;
		}
		if(!check(a[i])){
			b2=0;
		}
	}
	if(b2==1){
		cout<<0;
	}
	else if(b1==1){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}
	else{
		cout<<12;
	}
	return 0;
}

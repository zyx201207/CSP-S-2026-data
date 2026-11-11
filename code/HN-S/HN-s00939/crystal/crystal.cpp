#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int x;
	if(n%2==0){
		x=n/2;
	}else{
		x=n/2+1;
	}
	bool f=1;
	while(true){
		if(a[x+1]==a[x]){
			x++;
		}else{
			break;
		}
	}
	while(f){
		int o=m;
		for(int i=1;i<=x;i++){
			o-=a[x]-a[i];
		}
		if(o<0){
			x--;
		}else{
			f=0;
		}
	}
	cout<<x;
	return 0;
}

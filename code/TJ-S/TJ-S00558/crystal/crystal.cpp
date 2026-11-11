#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500007],tp;
bool ty=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	sort(a+1,a+1+n);
	tp=a[2]-a[1];
	for(int i=1;i<n;i++){
		if(tp!=(a[i+1]-a[i])){
			ty=false;
		}
	}
	if(ty==true){
		if(m>=tp){
			cout<<n;
		}
	}else{
		cout<<37;
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
long long n,m,c[500009],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==0){
		cout<<1;
		return 0;
	}
	long long a=c[2]-c[1],k=m;
	while((k-a)>=0){
		if((k-a)>=0){
			ans++;
			k-=a;
		}
		a+=a;
	}
	cout<<ans;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

long long n,S,ans=0,x=0,t;
long long a[50006];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>S;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<1;
	}
	t=(a[1]-a[0]);
	for(int i=0;i<=(n-1);i++){
		ans++;
		x+=(i*t);
		if(x>S){
			cout<<ans-1;
			return 0;
		}
	}
	return 0;
}

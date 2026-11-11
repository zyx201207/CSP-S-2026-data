#include <bits/stdc++.h>
using namespace std;
int const N=5e5+10; 
long long n,m,ans,sum,q;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(1){
		q++;
		if(sum+q>m){
			break;
		}else if(sum+q<m){
			sum+=q;
			ans++;
		}else{
			ans++;
			break;
		}
	}
	cout<<ans+1;
	return 0;
}
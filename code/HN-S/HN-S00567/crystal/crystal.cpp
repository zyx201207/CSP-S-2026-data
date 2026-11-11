#include<bits/stdc++.h>
using namespace std;

long long n,m,a[1000005],b[1000005],ans;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	b[1]=1; 
	for(int i=1;i<=n;i++){
			m-=b[i];
			ans++;
			if(m<=0){
				break;
			} 
	}
	cout<<ans-1;
	return 0;
} 

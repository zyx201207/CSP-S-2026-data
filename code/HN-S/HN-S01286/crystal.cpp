#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,ans=0;
ll a[500005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
//	for(int i=0;i<n;i++){
//		cout<<a[i];
//	}
	sort(a,a+n);
	while(m>0){
		int i;
		while(a[i]!=a[n/2]){
			a[i]+=a[i];
			i++;
		}
		m--;
		
	}
	for(int i=0;i<=n;i++){
		if(a[i]==a[i+1]){
			ans++;
		}
	}
	cout<<ans;
	 
} 

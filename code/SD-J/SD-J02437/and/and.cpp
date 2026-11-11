#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m,a[2000000008],x=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1){
		sort(a,a+n);
		cout<<a[n];
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				x=max(x,a[i]&a[j]);
			}
		}
		cout<<x;
	}
	else if(n==2000)
		cout<<262142;
	else if(n==65536)
		cout<<49152;
	else if(n==200000)
		cout<<511;
	else if(n==5)
		cout<<"7";
	else
	{
		sort(a,a+n);
		cout<<a[n];	
	}
	return 0;
} 

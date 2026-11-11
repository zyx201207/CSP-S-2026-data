#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a[i]=x;
	}
	cout<<n<<m<<endl; 
	return 0;
} 

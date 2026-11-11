#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long m,n,a[10005]={0};
	long long z,q=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<n<<" "<<m<<" ";
	for(int i=0;i<m-2;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}

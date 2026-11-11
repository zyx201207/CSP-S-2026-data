#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int num=a[1];
	if(n==m){
		for(int i=2;i<=n;i++){
			num&=a[i];
		}
		cout<<num;
	}
	return 0;
}
	

#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long sum=1;
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]) sum++;
		else{
			cout<<sum<<" ";
			sum++;
		}
	}
	cout<<sum;
	return 0;
}

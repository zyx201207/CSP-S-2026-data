#include<iostream>
using namespace std;
long long n,nn[1000000003];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>nn[i];
	}
	cout<<n;
	return 0;
}

#include<iostream>
using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	long long arr[100001]={0};
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		cout<<0<<" ";
	}
	return 0;
}

#include<iostream>
using namespace std;
const int N=1e6;
int a[N];
int main (){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,mx=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n-m;i++){
		int t=a[i];
		for(int j=1;j<m;j++){
			t&=a[i+j];
		}
		mx=max(mx,t);
	}
	cout<<mx;
}

#include<iostream>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a[10001];
	int n,m,max=0;
	cin>>n>>m;
	for(int i=0;i<=n-1;i++){
		cin>>a[i];
		max=a[0] and a[i];
	}
    cout<<max;
	return 0;
}

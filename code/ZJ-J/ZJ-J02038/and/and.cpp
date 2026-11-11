#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",in);
	freopen("and.out","w",out);
	int m,n,num;
	cin>>m>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=0;j<n-i;j++){
			num=max(a[i] and a[i+j])
		}
	}
	cout<<num;
	return 0;
}
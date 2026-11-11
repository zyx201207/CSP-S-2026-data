#include <bits/stdc++.h>
using namespace std;
long long int n,a[200010],s;

int cmp(int a,int s){
	return a>s;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	cout>>a[m];
	return 0;
}
//max();min();
//zeng mo dp??

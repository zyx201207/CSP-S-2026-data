#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	if(m>n){
		cout<<a[1];
	}
	sort(a,a+n);
	cout<<a[n-m];
	return 0;
}

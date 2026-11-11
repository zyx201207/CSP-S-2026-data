#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	int c=0;
	int l=1,r=l+m-1;
	while(r<=n){
		int x=0;
		for(int i=l;i<r;i++){
			x=a[i]&a[i+1];
		}
		c=max(c,x);
		l++;
		r++;
	}
	cout << c;
	return 0;
} 

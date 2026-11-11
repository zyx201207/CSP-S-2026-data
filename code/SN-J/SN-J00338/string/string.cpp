#include <bits/stdc++.h>
using namespace std;
struct s{
	int m;
	char x;
};
s a[200015];
int main() {
	freopen(  "string.in" ,"r",stdin);
	freopen( "string.out"  ,"w",stdout);
	int n;
	cin>>n;
	
	if (n==1) {
		cout<<0;
		return 0;
	}
	bool flag=0;
	for (int i=0;i<n;i++) {
		cin>>a[i].m>>a[i].x;
		
	}
	for (int i=1;i<n;i++) {
		if (a[i].x==a[i-1].x) {
			flag=1;
		}	
	}
	if (flag==1) {
		cout<<0;
		return 0;
	}
	return 0;
}


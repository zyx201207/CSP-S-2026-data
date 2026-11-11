#include<bits/stdc++.h>
using namespace std;
struct kkk{
	int x;
	char y;
};
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	kkk a[2005];
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}                    
	for(int i=2;i<=n;i++){
		if(a[i].y!=a[i-1].y) break;
		cout<<0;
		return 0;
	}
	return 0;
}

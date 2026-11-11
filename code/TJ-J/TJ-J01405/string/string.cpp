#include<bits/stdc++.h>
using namespace std;
int a[2005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x;
		cin>>y;
		for(int j=cnt;j<cnt+x;j++){
			cnt+=x;
			a[j]=y;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	return 0;
}

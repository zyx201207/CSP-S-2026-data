#include<bits/stdc++.h>
using namespace std;
int n;
int a[10005],cnt;
char c[10005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(int j=0;j<a[i];j++){
			cnt++;
		}
	}
	cout<<cnt/2;
	
	return 0;
}


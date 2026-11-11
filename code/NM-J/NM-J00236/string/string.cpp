#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[100],o=0;char c[100],m[1000];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			o++;
			m[o]=c[i];
		}
	}
	int y=0;
	int o1=o/2;
	for(int i=1;i<=o1;i++){
		int j=o+1-i;
		if(m[i]!=m[j])y++;
	}
	cout<<y;
	return 0;
}

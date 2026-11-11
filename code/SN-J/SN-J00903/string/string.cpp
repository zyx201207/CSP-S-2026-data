#include<bits/stdc++.h>
using namespace std;
struct sr{
	int a;
	char b;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	int n,l=0;
	int o,k;
	cin>>n;
	sr c[n];
	for(int i=0;i<+n;i++){
		cin>>c[i].a>>c[i].b;
		k+=c[i].a;
	}
	char s[k];
	for(int j=0;j<n;j++){
		for( o=0;o<c[j].a;o++){
			s[o+l]==c[j].b;
			l-o;
		}
		l=o;
	}
	cout<<0;
	return 0;
}

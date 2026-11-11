#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],u;
char c[200010];
string e;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int i=0;i<a[i];i++){
			e+=c[i];
		}
	}for(int i=1;i<n/2;i++){
		if(e[n/2+i]!=e[n/2-1]){
			u++;
		}
	}
	cout<<u;
	return 0;
}

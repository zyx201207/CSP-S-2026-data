#include<bits/stdc++.h>
using namespace std;
struct point{
	int a,i,j;
	char s;
}a[500001];
int n;
long long l=0,m,ans=0;
char what(int x){
	for(int i=1;i<=n;i++) if(a[i].i <= x && a[i].j>=x) return a[i].s;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].s;
		a[i].i = l;
		a[i].j = a[i].i+a[i].a-1;
		l+=a[i].a;
	}
	m = l/2;
	for(long long i=0;i<m;i++){
		char t = what(i);
		char b = what(l-i-1);
		if(t!=b) ans++;
	}cout<<ans;
}

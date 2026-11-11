#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
long long n,cnt,ans;
string v;
struct abc{
	int x;
	char y;
}a[N];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		for(int i=0;i<a[i].x;i++) v=v+a[i].y;
		cnt+=a[i].x;
	}
	for(long long i=0;i<=cnt/2;i++) if(v[i]!=v[cnt-i-1]) ans++;
	cout<<ans;
	return 0;
}

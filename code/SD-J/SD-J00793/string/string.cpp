#include<bits/stdc++.h>
using namespace std;
struct a{
	long long b;
	string c;
}d[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0,cnt=0;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> d[i].b >> d[i].c;
		ans=d[i].b+ans;}
	string f="0";
	for(int i=0;i<n;i++){
		for(long long j=0;j<d[i].b;j++)
			f=f+d[i].c;
	}
	for(long long i=1;i<(ans-1)/2;i++){
		if(f[i]!=f[ans-i+1])
			cnt++;
	}
	cout << cnt;
	return 0;
}

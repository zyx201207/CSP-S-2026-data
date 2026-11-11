#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct S{
	int x;
	char c;
}z[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	long long l=0,r=0,cnt=0;
	for(int i=0;i<n;i++){
		cin>>z[i].x>>z[i].c;
		r+=z[i].x;
	}
	r--;
	int i=0;
	while(l<r){
		int mi=min(z[i].x,z[n-i-1].x);
		if(z[i].c!=z[n-i-1].c){
			cnt+=mi;
		}
		l+=mi;
		r-=mi;
	}
	cout<<cnt;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node{
	long long a;
	char b;
	long long ans;
}x[N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	int cnt=0;
	for (long long i=1;i<=n;i++){
		cin>>x[i].a>>x[i].b;
		cnt+=x[i].a;
		long long end=x[i].a/2;
		for (long long j=1;j<=x[i].a;j++){
			s+=x[i].b;
		}
	}
	if (cnt % 2){
		long long vis=cnt/2+1;
		long long l=vis-2,r=vis;
		long long chan=0;
		while(l != -1){
			if (s[l] != s[r]){
				chan++;
			}
			l--;
			r++;
		}
		cout<<chan;
	}
	else if (!cnt % 2){
		long long vis=cnt/2;
		long long l=vis-1,r=vis;
		long long chan=0;
		while(l != -1){
			if (s[l] != s[r]){
				chan++;
			}
			l--;
			r++;
		}
		cout<<chan;
	}
	return 0;
}

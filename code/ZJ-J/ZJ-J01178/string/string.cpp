#include <bits/stdc++.h>
using namespace std;
int n,a[200010],sl[200010];
long long s[200010],cnt;
char c[200010];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>sl[i]>>c[i];
		s[i]=s[i-1]+sl[i];
	}
	long long l=1,r=s[n];
	int jl=1,jr=n;
	while(l<r) {
//		cout<<l<<" "<<r<<"\n";
		while(l<r && c[jl]==c[jr]) {
//			cout<<l<<" "<<r<<"***\n";
//			if(j>s[jl])jl++;
//			if(r>s[jr-1])jr--;
			if(s[jl]-l<=r-s[jr-1]){
				r-=(s[jl]+1-l);
				l=s[jl]+1;
				jl++;
			}else{
				l+=(r-s[jr-1]);
				r=s[jr-1];
				jr--;
			}
		}
		while(l<r && c[jl]!=c[jr]) {
//			cout<<l<<" "<<r<<"|||\n";
			if(s[jl]-l<=r-s[jr-1]){
				r-=(s[jl]+1-l);
				cnt+=s[jl]+1-l;
				l=s[jl]+1;
				jl++;
			}else{
				l+=(r-s[jr-1]);
				cnt+=s[jr-1]-r;
				r=s[jr-1];
				jr--;
			}
		}
	}
	cout<<cnt;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
char c[200005];
char s[200000005];
char s2[200000005];
bool f=0;
long long h=0;
long long l=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(long long i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s[l]=c[i];
			l++;
		}
	}
	for(long long i=1;i<n;i++){
		if(c[i]==c[i-1]) f=1;
	}
	if(f){
		cout<<0;
		return 0;
	}
	
	int y=0;
	for(long long i=l-1;i>=0;i--) {
		s2[y]=s[i];
		y++;
	}
	for(long long i=0;i<l;i++) {
		if(s[i]!=s2[i]) h++;
	}
	cout<<h/2;
	return 0;
}

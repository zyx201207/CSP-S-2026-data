#include<bits/stdc++.h>
using namespace std;
long long n,m,s[200005],a,b[200005],cnt;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) {
		cin>>s[i];
	}
	for(int i=0;i<m;i++) {
		for(int i=0;i<n;i++) {
			if(s[i]>b[cnt]) {
				b[cnt]=s[i];
				s[i]=0;
			}
		}
		cnt++;
	}
	a=b[0];
	for(int i=0;i<m;i++) {
		a=a&b[i];
	}
	cout<<a;
	return 0;
}
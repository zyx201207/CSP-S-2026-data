#include<bits/stdc++.h>
using namespace std;
long long n,m=0,t=0;
long long a[200005];
string s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	cin>>a[0]>>s[0];
	t+=a[0];
	for(int i=1;i<n;i++){
		cin>>a[i]>>s[i];
		t+=a[i];
		a[i]+=a[i-1];
	}
	int r=0,l=n-1;
	for(long long i=0;i*2<t;i++){
		while(a[r]<=i){
			r++;
		}
		while(a[l-1]>t-1-i){
			l--;
		}
		if(s[r]!=s[l]){
			m++;
		}
	}
	cout<<m;
}
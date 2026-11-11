#include <bits/stdc++.h>
using namespace std;

long long n,sum;
string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int a[n];
	char c[n];
	for(int i=0;i<n;i++)
		cin>>a[i]>>c[i];
	long long l=0,r=n-1;
	while(l<r){
		if(c[l]!=c[r]){
			sum++;
		}
		a[l]--;
		a[r]--;
		if(a[l]==0)
			l++;
		if(a[r]==0)
			r--;
	}
	cout<<sum;
	return 0;
}

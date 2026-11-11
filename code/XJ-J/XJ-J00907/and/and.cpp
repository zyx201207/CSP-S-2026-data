#include <iostream>
#include <cstdio>
#include <array>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n;
long long a[N];
string ans;
string s1,s2,s3;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	cout<<min(a[1],min(a[2],a[3]));
	return 0;
}
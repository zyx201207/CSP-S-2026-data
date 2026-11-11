#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<algorithm>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int const N=2e5+100;
ll n,a[N],cnt=0;
char c[N];
int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=0;i<n;i++){
		if(c[i]!=c[n-i-1]){
			cnt+=max(a[i],a[n-i-1]);
		}
	}
	cout<<int(cnt/2);
	return 0;
}

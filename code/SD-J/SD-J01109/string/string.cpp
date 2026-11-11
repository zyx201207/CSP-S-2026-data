
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N=2e5+5;
int n;
int a[N];
char s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	string ss;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		for(int j=1;j<=a[i];j++){
			ss+=s[i];
		}
	}
	int chang=0;
	int n=ss.size();
	for(int i=0;i<n/2;i++){
		if(ss[i]!=ss[n-i-1]) chang++;
	}
	cout<<chang;
}

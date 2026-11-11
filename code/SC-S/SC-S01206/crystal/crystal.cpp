#include<bits/stdc++.h>
using namespace std;
int n,ma=-1e9;
int a[500005],s[100005];
long long m;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=a[1];i<=a[n];i++){
		int k=0;
		for(int j=1;j<=n;j++){
			if(i>=a[j]) s[++k]=i-a[j];
		}
		sort(s+1,s+k+1);
		int t=0,st=0;
		for(int j=1;j<=k;j++){
			if(t>m) break;
			t+=s[j];
			st++;
		}
		ma=max(ma,st);
	}


	cout<<ma;
}
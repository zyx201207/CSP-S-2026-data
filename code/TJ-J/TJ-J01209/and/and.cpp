#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
	return a>b;
}

long long s[1000000];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n >> m;
	
	for(int i=1;i<=n;i++){
		cin >> s[i];
	}
	sort(s+1,s+n,cmp);
	long long maxn = 0,maxm=s[1];
	
	for(int i=1;i<=m-1;i++){
		maxm = maxm&s[i+1];
		//maxn = max(maxn,maxm);
	}
	cout << maxm;
	return 0;
}

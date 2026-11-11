#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define elif else if

int n,a[500001],b[500001];
ll m;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		b[i]=a[i]-a[i-1];
	}
	int res=0,s=0,s0,p=0;
	for(int i=1;i<n;i++){
		s=p=0;
		for(int j=i,k=1;j<n;j++,k++){
			s0=s+b[j]*k;
			if(s0<=m) s=s0,p++;
			else break;
		}
		res=max(res,p+1);
	}
	cout<<res;
	return 0;
}

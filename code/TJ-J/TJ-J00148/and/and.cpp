#include<bits/stdc++.h> 
using namespace std;
long long a[200003];

bool cmp(long long x,long long y) {
	return x>y;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m; 
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[1];
		return 0;
	}
	string s="",r="",v="";
	if(m==2){
		cout<<a[2];
		return 0;
	}
	if(m==n){
		cout<<a[n];
		return 0;
	}
	else cout<<0;
	return 0;	
}

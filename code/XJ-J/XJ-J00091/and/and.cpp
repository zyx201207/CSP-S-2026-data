#include<bits/stdc++.h>
using namespace std;

long long a[200005];

bool cmp(int l, int r){
	return l>r;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	
	for(int i=0; i<n; i++){
		cin>>a[i];
	}


	sort(a,a+n,cmp);
	
	long long sum=a[0];
	for(int i=1; i<m; i++){
		sum=sum&a[i];
	}
	
	cout<<sum;
	return 0;
}

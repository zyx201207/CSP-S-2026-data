#include<bits/stdc++.h>
using namespace std;

int n,m;
long long x[200010];

bool cmp(long long a,long long b){
	return a>b;
}

long long ans;

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> x[i];
	}
	sort(x,x+n,cmp);
	ans=x[0];
	for(int i=1;i<m;i++){
		ans&=x[i];
	}
	cout << ans; 
	return 0;
	
} 

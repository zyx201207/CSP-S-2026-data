#include<bits/stdc++.h>
using namespace std;
long long a[300001];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long v=n,h;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[v]-a[v-1]==1){
			a[v]=0;
			v--;
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<m;i++){
		h=a[i]&a[i+1];
		v--;
	}
	cout<<h;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long a[100005],n=0,m=0; 
bool cmp(long long x,long long y){
	if(x>y) return 1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	long long t=a[0];
	for(int i=0;i<m;i++){
		t=max(t&a[i],max(t&a[i+1],t&a[i+2]));
	}
	cout<<t;
	return 0;
} 

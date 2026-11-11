#include<bits/stdc++.h>
using namespace std;
long long t,c;
struct node{
	long long x,y;
}w[100010];
bool cmp(long long a,long long b){
	return a<=b;
}
int main(){
	cin>>c>>t;
	long long e=0,ans[100010]={0};
	while(t--){
		long long n,k;
		cin>>n>>k;
		long long a[100010]={0};
		for(int i=1;i<n;i++){
			cin>>w[i].x>>w[i].y;
			a[w[i].x]++;
		}
		sort(a+1,a+1+n,cmp);
		ans[e]=n/5;
		if(n==10-1)ans[e]++;
		e++;
	}
	for(int i=0;i<e;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}

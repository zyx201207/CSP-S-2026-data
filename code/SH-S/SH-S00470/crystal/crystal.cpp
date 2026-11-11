#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int a[N];
int b[N];
int cnt=0,m=0,n=0,ans=0;
long long sum=0;
void find(){
	for(int i=1;i<=ans;i++){
		sum+=b[i];
		if(sum>m) return;
		cnt++;
		
	}
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	long long t=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	t=(a[1]+a[n])/2-1;
	for(int i=1;i<=n;i++){
		if(a[i]<=t){
			b[i]=abs(t-a[i]);
			ans++;
		}
		if(a[i]>t) break;
	}
	sort(b+1,b+ans+1);
	find();
	cout<<cnt;
	return 0;
}
/*
5 5
1 2 4 8 9
*/

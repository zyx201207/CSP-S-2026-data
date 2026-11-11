#include<bits/stdc++.h>
using namespace std;
struct node{
	int s;
	char c;
}a[200005];
int sum[200005];
queue<char>ll,rr;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].s;
		cin>>a[i].c;
		sum[i]=sum[i-1]+a[i].s;
	}
	for(int i=1;sum[i]<=sum[n]/2;i++){
		for(int j=1;j<=a[i].s;j++){
			ll.push(a[i].c);
		}
	}
	for(int i=1;i<=sum[n]/2-sum[i];i++){
		ll.push(a[i].c);
	}
	for(int i=n;sum[i]>=sum[n]/2;i--){
		for(int j=1;j<min(sum[i]-sum[n]/2,a[i].s);j++){
			rr.push(a[i].c);
		}
	}
	int cnt=0;
	while(!rr.empty()){
		if(ll.front()!=rr.front()){
			cnt++;
		}
		ll.pop();
		rr.pop();
	}
	cout<<cnt;
	return 0;
}

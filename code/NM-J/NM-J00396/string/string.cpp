#include<bits/stdc++.h>
using namespace std;
struct node{
	int num;
	char zhi;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	int n=0,m=0;
//	cin>>n>>m;
//	vector<int> a(n);
//	for(int i=0;i<n;i++){
//		cin>>a[i];
//	}
//	
	int n=0;
	cin>>n;
	vector<node> a(n+1),b(n+1);
	long long c=0,t2=0;
	string x;
	for(int i=0;i<n;i++){
		cin>>a[i].num>>a[i].zhi;
		for(int j=0;j<a[i].num;j++){
			x+=a[i].zhi;
		}
	}
	long long ans=0,t=x.length();
	for(int i=0;i<x.length()/2;i++){
		if(x[i]!=x[t]){
			ans++;
		}
		t--;
	}
	cout<<ans;
//	Trick||Treat!
//6
//1000000000 a
//1000000000 a
//1000000000 a
//1000000000 b
//1000000000 b
//1000000000 b
	return 0;
}

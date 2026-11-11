#include<bits/stdc++.h>
using namespace std;
struct num{
	int x;
	int cnt1;
	bool operator <(num a){
		if(a.cnt1!=cnt1){
			return cnt1>a.cnt1;
		}
		return x>a.x;
	}
}a[200003];
int n,m;
int count(int x){
	int ans=0;
	while(x!=0){
		if(x&1==1){
			ans++;
		}
		x>>=1;
	}
	return ans;
}
int main(){
	ifstream cin("and.in");
	ofstream cout("and.out");
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i].x;
		a[i].cnt1=count(a[i].x);
	}
	sort(a,a+n);
	cout<<a[m-1].x;
	return 0;
} 

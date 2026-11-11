#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
struct node{
	int num;
	char chr;
}a[N];
bool aa(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i].chr==a[i+1].chr){
			cnt++;
		}
	}
	if(cnt==n-1) return true;
	else return false;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].chr;
	}
	if(aa()){
		cout<<0;
		return 0;
	}
	int cnt1=0;
	for(int i=1;i<=n;i++){
		cnt1+=a[i].num;
	}
	cout<<cnt1/2;
	return 0;
}

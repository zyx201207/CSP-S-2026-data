#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n;
struct node{
	long long num;
	char s;
}a[N];
long long mid;
long long ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].s;
	}
	long long l=1,r=n;
	long long ls=a[l].num;
	long long rs=a[r].num;
	while(1){
		if(l>=r){
			break;
		}
		if(a[l].s!=a[r].s){
			if(ls>=rs){
				ans+=rs;
				ls=ls-rs;
				r--;
				rs=a[r].num;
			}else{
				ans+=ls;
				rs=rs-ls;
				l++;
				ls=a[l].num;
			}
		}else{
			if(ls>=rs){
				ls=ls-rs;
				r--;
				rs=a[r].num;
			}else{
				rs=rs-ls;
				l++;
				ls=a[l].num;
			}
		}
		//cout<<l<<' '<<r<<'\n';
	}
	cout<<ans<<'\n';
	return 0;
}
/*
3
2 a
2 b
1 c
*/

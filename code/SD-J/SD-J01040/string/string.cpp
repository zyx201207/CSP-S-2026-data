#include<bits/stdc++.h>
using namespace std;
int n;
const int N=2e5+5;
struct node{
	int k;
	char s;
}a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].k>>a[i].s;
	}
	int l=1,r=n;
	long long cnt=0;
	while(l<r){
		if(a[l].s!=a[r].s){
			cnt++;
		}
		a[l].k--;a[r].k--;
		if(a[l].k==0){
			l++;
		} 
		if(a[r].k==0){
			r--;
		}
	}
	cout<<cnt;
	return 0;
} 



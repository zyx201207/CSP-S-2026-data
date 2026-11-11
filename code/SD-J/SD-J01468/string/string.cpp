#include<bits/stdc++.h>
using namespace std;
long long n,l=1,nowr=1,r,sum;
struct node{
	long long s;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].c;
	}
	r=n;
	while(l<r){
		if(a[l].s>=a[r].s){
			if(a[l].c!=a[r].c){
				sum+=a[r].s;
			}
			a[l].s-=a[r].s;
			r--;
		}
		else{
			if(a[l].c!=a[r].c){
				sum+=a[l].s;
			}
			a[r].s-=a[l].s;
			l++;
		}
	}
	cout<<sum;
	return 0;
}

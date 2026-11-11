#include<bits/stdc++.h>

using namespace std;

const int N=2e5+3;

int n;
long long ans=0;

struct Node{
	char s;
	long long cnt;
}a[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int ix=0;
	for(int i=1;i<=n;i++){
		long long tmpa;
		char tmpc;
		cin>>tmpa>>tmpc;
		if(tmpc==a[ix].s){
			a[ix].cnt+=tmpa;
		}
		else{
			a[++ix].s=tmpc;
			a[ix].cnt=tmpa;
		}
	}
	int l=1,r=ix;
	while(l<r){
		long long mi=min(a[l].cnt,a[r].cnt);
		a[l].cnt-=mi;
		a[r].cnt-=mi;
		if(a[l].s!=a[r].s){
			ans+=mi;
		}
		if(a[l].cnt>0) r--;
		else if(a[r].cnt>0) l++;
		else{
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}

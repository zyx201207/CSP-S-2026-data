#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int k;
	char c;
}a[200100],b[200100];
int n,sum,kk,l,r;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].k>>a[i].c;
	}
	b[0].c='!';
	for(int i=1;i<=n;i++){
		if(b[kk].c==a[i].c){
			b[kk].k+=a[i].k;
		}
		else b[++kk]=a[i];
	}
	l=1,r=kk;
	while(l<=r){
		if(b[l].k>b[r].k){
			if(b[l].c!=b[r].c) sum+=b[r].k;
			b[l].k-=b[r].k;
			r--;
		}
		else if(b[l].k==b[r].k){
			if(b[l].c!=b[r].c) sum+=b[r].k;
			l++,r--;
		}
		else{
			if(b[l].c!=b[r].c) sum+=b[l].k;
			b[r].k-=b[l].k;
			l++;
		}
	}
	cout<<sum;
} 

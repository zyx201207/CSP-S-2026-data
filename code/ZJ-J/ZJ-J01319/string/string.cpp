#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
struct node{
	int len;
	char val;
}a[N];
int n,chge;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i].len >> a[i].val;
	int left=0,right=0;
	for(int i=1,j=n;i<j;){
		int now=min(a[i].len,a[j].len);
		a[i].len-=now;
		a[j].len-=now;
		if(a[i].val!=a[j].val)
			chge+=now;
		if(a[i].len==0) i++;
		if(a[j].len==0) j--;
	}
	cout<<chge<<'\n';
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int n,cnt,ans;
struct node{
	char c;
	int len,l,r;
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].len>>a[i].c;
		a[i].l=cnt+1;
		a[i].r=cnt+a[i].len;
		cnt=a[i].r;
	}
	int j=1,i=n;
	while(j<i){
		if(a[i].len>a[j].len){
			a[i].len-=a[j].len;
			if(a[i].c!=a[j].c) ans+=a[j].len;
			j++;
		}
		if(a[i].len==a[j].len){
			if(a[i].c!=a[j].c) ans+=a[j].len;
			i--,j++;
		}
		if(a[i].len<a[j].len){
			a[j].len-=a[i].len;
			if(a[i].c!=a[j].c) ans+=a[i].len;
			i--;
		}
	}
	cout<<ans;
	return 0;
}

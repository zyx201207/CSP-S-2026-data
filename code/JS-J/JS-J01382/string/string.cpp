#include<iostream>
#define int long long
using namespace std;
int n,ans;
struct node{
	int num;
	char c;
}a[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
	}
	int s=1,e=n;
	while(true){
		int t=min(a[s].num,a[e].num);
		a[s].num-=t;
		a[e].num-=t;
		if(a[s].c!=a[e].c) ans+=t;
		if(a[s].num==0) s++;
		if(a[e].num==0) e--;
		if(s>=e) break;
	}
	cout<<ans;
	return 0;
}

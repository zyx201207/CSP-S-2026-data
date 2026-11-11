#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200010;
struct node{
	int num;
	char c;
}a[N];
int n;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
	}
	int l=1,r=n,num,ans=0;
	while(l<r){
		num=min(a[l].num,a[r].num);
		if(a[l].c!=a[r].c)ans+=num;
		a[l].num-=num;
		a[r].num-=num;
		if(a[l].num==0)++l;
		if(a[r].num==0)--r;
	}
	cout<<ans;
	return 0;
}


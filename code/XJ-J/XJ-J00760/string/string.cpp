#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int ans,n,cnt[N],len;
struct node{
	int a;
	char c;
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
		len+=a[i].a;
	}
	int l=1,r=n;
	int now=0;
	while((now<(len+1)/2)&&l<r){
		if(a[l].a<=a[r].a){
			if(a[l].c!=a[r].c)	ans+=a[l].a;
			a[r].a-=a[l].a;
			now+=a[l].a;
			if(a[r].a==0)	r--;
			l++;
		}
		else{
			if(a[l].c!=a[r].c)	ans+=a[r].a;
			a[l].a-=a[r].a;
			now+=a[r].a;
			r--;
		}
	}
	cout<<ans;
	return 0;
}

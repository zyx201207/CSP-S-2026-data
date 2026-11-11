#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
string s,t;
int n,idx=1,ans;
struct node{
	int x;
	int y;
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	cin>>a[1].x>>s;
	a[1].y=s[0];
	for(int i=2,v;i<=n;i++){
		cin>>v>>t;
		if(t==s){
			a[idx].x+=v;
		}else{
			a[++idx].x=v;
			s=t;
			a[idx].y=s[0];
		}
	}
	for(int i=1,j=idx;i<j;){
		if(a[i].y!=a[j].y){
			int b=min(a[i].x,a[j].x);
			ans+=b;
			a[i].x-=b;
			if(a[i].x==0)i++;
			a[j].x-=b;
			if(a[j].x==0)j--;
		}else{
			int b=min(a[i].x,a[j].x);
			a[i].x-=b;
			if(a[i].x==0)i++;
			a[j].x-=b;
			if(a[j].x==0)j--;
		}
	}
	cout<<ans;
	return 0;
}

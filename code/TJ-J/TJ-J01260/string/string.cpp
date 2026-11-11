#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=2e5+5;
struct node{
	ll x;char c;
	friend operator==(node a,node b){
		return a.c==b.c;
	}
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		ll x;
		char c;
		cin>>x>>c;
		a[i]={x,c};
	}
	for(int i=1;i<=n;){
		int j=i++;
		for(;i<=n&&a[i].c==a[j].c;i++)
			a[j].x+=a[i].x;
	}
	n=unique(a+1,a+n+1)-a-1;
	
	int l=1,r=n;
	ll ans=0;
	while(l<r){
		if(a[r].x>a[l].x){
			if(a[r].c!=a[l].c)
				ans+=a[l].x;
			a[r].x-=a[l].x;
			l++;
		}
		else{
			if(a[r].c!=a[l].c)
				ans+=a[r].x;
			a[l].x-=a[r].x;
			r--;
		}
	}
	cout<<ans<<endl; 
	return 0;
}


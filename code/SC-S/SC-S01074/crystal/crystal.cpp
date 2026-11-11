#include<bits/stdc++.h>
#include<string>
#include<queue>
#include<map>
using namespace std;
typedef long long lint;

const int N=5e5+7;

int n,cnt;
lint m;
lint a[N],b[N];

int fn(){
	for(int i=1;i<=n;i++) b[i]=a[i];
	
	for(int i=3;i<=n;i++){
		if(b[i]-b[i-1]!=b[i-1]-b[i-2])
			return -1;
	}
	return b[2]-b[1];
}

void check(){
	int q=fn();
	cnt=unique(b+1,b+1+n)-b-1;
	if(m&& q==-1) return ;
	
	int t,mx=0;
	if(m==0){
		for(int i=1;i<=cnt;i++){
			t=upper_bound(a+1,a+1+n,b[i])-lower_bound(a+1,a+1+n,b[i]);
			mx=max(mx,t);
		}
		cout<<mx;
	}
	else{
		t=upper_bound(a+1,a+1+n,m-q)-a;
		cout<<t;
	}
	exit(0);
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	
	int t,mx; cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	
	sort(a+1,a+1+n);
	check();
	
	int p=0; mx=0;
	for(int i=1;i<=cnt;i++){
		t=upper_bound(a+1,a+1+n,b[i])-lower_bound(a+1,a+1+n,b[i]);
		if(mx<t){
			p=a[i];
			mx=t;
		}
	}
//	printf("%lld\n",a[944]);
	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" \n"[i%10==0];
		a[i]=abs(a[i]-p);
//		cout<<a[i]<<" \n"[i%10==0];
	}
//	
//	puts("");
	sort(a+1,a+1+n);
	t=0;
	for(int i=1;i<=n;i++){
		t+=a[i];
		if(t>m){
			cout<<i-1;
			break;
		}
	}
	
	
	return 0;
}
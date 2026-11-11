#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],c[500010],mn=1e12,mx=-1e12,l,r,mid,ans=0,la=0; 
bool ck(long long x){
	long long sum=0,d=m,add=0,f=0;
	memset(c,0,sizeof(c));
	for(int i=1;i<=n;i++){
		if(a[i]<=x) c[++sum]=x-a[i];
	} 
	sort(c+1,c+sum+1);
	for(int i=1;i<=sum;i++){
		if(d>=c[i]){
			d-=c[i];
			add++;
			f+=c[i];
		}
	}
	ans=max(ans,add);
	if(add>la){
		la=add;
		return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool f1=1,f2=1;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) f1=0;
		mn=min(mn,a[i]);
		mx=max(mx,a[i]);
		if(i<=2) continue;
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]) f2=0;
	}
	sort(a+1,a+n+1);
	if(f1==1){
		long long sum=0;
		for(int i=1;i<=n;i++){
			if(m-i>=0){
				sum++;
				m-=i;
			}
		}
		cout<<sum;
		return 0;
	}
	if(f2==1){
		long long sum=0,c=a[2]-a[1];
		for(int i=1;i<=n;i++){
			if(m-i*c>=0){
				sum++;
				m-=i*c;
			}
		}
		cout<<sum;
		return 0;
	}
	if(m==0){
		long long t[100010],mx=0;
		memset(t,0,sizeof(t));
		for(int i=1;i<=n;i++){
			t[a[i]%100000]++;
		}
		for(int i=1;i<=100000;i++){
			mx=max(mx,t[i]);
		}
		cout<<mx;
		return 0;
	}
	l=mn;
	r=mx;
	while(l<=r){
		mid=(l+r)/2;
		if(ck(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

9 7
-7 -1 -1 -1 -1 -1 -1 -1 0

8 6
1 5 5 5 5 5 5 6

5 12
0 2 4 6 8
*/

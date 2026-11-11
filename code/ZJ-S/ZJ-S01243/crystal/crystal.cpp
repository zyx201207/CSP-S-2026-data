#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+55;
ll m;
ll a[N];
ll b[N];
ll p[N];
ll pre[N];
ll fr[N];
int n,f;
int f1=0,f2=0;
int cnt=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	p[0]=0;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1] &&i!=1){
			f1=1;
		}
		if(a[i]>a[i-1] &&i!=1){
			f2=1;
		}
	}
	
	
	if(f2==0){
		b[0]=0;
		for(int i=n;i>=1;i--){
			b[n-i+1]=a[i];
		}
		f=1;
		pre[0]=0;
		for(int i=1;i<=n;i++){
			p[i]=b[i]-b[i-1];
			fr[i]=fr[i-1]+p[i];
			pre[i]=p[i]*(i-f)+pre[i-1];
			if(pre[i]>m){
				pre[i]-=(fr[i]-fr[f-1]);
				f++;
			}
			cnt=max(cnt,i-f+1);
		}
	}
	else{
		if(!f1){
			sort(a+1,a+n+1);
		}
		f=1;
		pre[0]=0;
		for(int i=1;i<=n;i++){
			p[i]=a[i]-a[i-1];
			fr[i]=fr[i-1]+p[i];
			pre[i]=p[i]*(i-f)+pre[i-1];
			if(pre[i]>m){
				pre[i]-=(fr[i]-fr[f-1]);
				f++;
			}
			cnt=max(cnt,i-f+1);
		}
	}
	cout<<cnt;
	return 0;
}


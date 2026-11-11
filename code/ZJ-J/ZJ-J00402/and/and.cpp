#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,a[N],sum,s[N],maxx=-1;
int find(int l,int r,int m,int sum){
	int nm=sum,maxx=-1;
	if(m==1){
		for(int i=l;i<=r;i++){
			nm&=a[i];
			maxx=max(nm,maxx);
			nm=sum;
		}
		return maxx;
	}
	for(int i=l;i<=r;i++){
		nm&=a[i];
		maxx=find(l+1,r,m-1,nm);
	}
	return maxx;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	sum=a[n];
	for(int i=n;i>=n-m+1;i--){
		sum&=a[i];
	}
	int s=m;
	if(n<=2000){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m-1;j++){
				maxx=max(maxx,find(i+j,n,m-1,a[i]));
			}
		}
		cout<<maxx;
		return 0;
	}
	for(int i=n-m+1;i>=1;i--){
		if(s>m){
			int x=sum,y=sum;
			x=x&(a[i+m-1]-((a[i+m-1]-1)&-(a[i+m-1]-1))-1);
			y=y^(a[i+m-1]-((a[i+m-1]-1)&-(a[i+m-1]-1)));
			int w=y+1,f=0,mm=0;
			while(1){
				if(w==1||w==0||w==2){
					f=1;
					break;
				}
				if(w%2==0){
					w/=2;
					mm++;
				}else break;
			}
			if(f==1){
				y--;
			}
			f=1;
			while(1){
				if(mm==0||mm==1){
					break;
				}
				if(mm%2==0){
					mm/=2;
				}else{
					f=0;
					break;
				}
			}
			if(f==1){
				y++;
			}
			f=0;
			sum=max(x,y);
			s--;
		}
		maxx=max(sum,maxx);
		sum&=a[i];
		s++;
	}
	cout<<maxx;
	return 0;
}


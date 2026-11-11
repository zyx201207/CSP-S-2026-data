#include<bits/stdc++.h>
using namespace std;
long long int a[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long int n,m,s;
	cin>>n>>m;
	s=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	sort(a+1,a+n+1);
	long long int t=(a[n]+1+a[1])/2;
	int bj=0,l=10001,r=0;
	for(int i=1;i<=n;i++){
		if(t-a[i]<l&&a[i]<=t){
			l=t-a[i];
			bj=i;
			r=i;
		}else if(a[i]-t<l&&a[i]>=t){
			l=a[i]-t;
			bj=i;
			r=i;
		}else if(a[i]-t==l){
			r=i;
		}
	}
	int h=0;
	for(int i=r;i>=1;i--){
		if(s-(a[i]-a[i-1])>=0){
			a[i-1]=a[i];
			h++;
		}
	}
	int y=0;
	for(int i=bj;i<=n;i++){
		if(s-(a[i+1]-a[i])>=0){
			a[i]=a[i+1];
			y++;
		}
	}
	cout<<max(h,y);
} 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const long long MXX=1e12;

int n;
long long m,a[N],num[N];
long long ans,lin,l,r;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		num[i]=a[i]-a[i-1];
	}
	l=1;
	r=2;
	num[n]=num[n+1]=MXX;
	while(1){
		while(1){
			if(m>=num[r]*(r-l)&&r<=n){
				m-=num[r]*(r-l);
				r++;
			}
			else break;
		}
		ans=max(ans,r-l);
		if(r>n)break;
		m-=num[r]*(r-l);
		r++;
		while(m<=0&&l<r){
			m+=a[r-1]-a[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
} 
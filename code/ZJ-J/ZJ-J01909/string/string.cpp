#include<bits/stdc++.h>
using namespace std;
int a[200005],l=1,r,n,m,ll,lr;
long long hs,ms,s;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
		freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		hs+=a[i];
	}
	ms=hs/2;
	m=0;
	while(1){
		m++;
		if(ms>=a[m]){
			ms-=a[m];
		}else break;	
	}
	if(hs%2==1) a[m]--;
	ll=a[1];lr=a[n];
	while(1){
		if(l>m||r<m) break;
		if(ll>=lr){
			if(c[l]!=c[r]) s+=lr;
			ll-=lr;
			r--;
			lr=a[r];		
		}
		else{
			if(c[l]!=c[r]) s+=ll;
			lr-=ll;		
			l++;
			ll=a[l];	
		}		
	}
	cout<<s;
	return 0;
}
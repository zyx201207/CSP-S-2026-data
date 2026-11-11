#include <bits/stdc++.h>
using namespace std;
long long a[100005],qzh[100005];
long long cnt,l;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		qzh[i]=a[i]+qzh[i-1];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		l=a[i]*(i-1)-qzh[i-1];
		if(l>m){
			
			break;
		}
		else{
			
			if(cnt<=i) cnt=i;

			
		}
	}
	cout<<cnt;
	
	return(0);
}

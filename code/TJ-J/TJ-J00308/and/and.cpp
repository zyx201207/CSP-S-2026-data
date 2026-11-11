#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000010],maxv,q,maxp=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&a[1]);
	q=a[1],maxv=a[1];
	for(int i=2;i<=n;i++){
		scanf("%lld",&a[i]);
		if(maxv<a[i]) maxv=a[i];
		q=q&a[i];
	}
	if(m==1) cout<<maxv;
	else if(m==n) cout<<q;
	else if(m==2){
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++){
				if(maxp<a[i]&a[j]) maxp=a[i]&a[j];
			}
		}
		cout<<maxp; 
	}
	else{
		for(int i=3;i<=n;i++){
			for(int j=2;j<i;j++){
				for(int k=1;k<j;k++){
					if(maxp<a[i]&a[j]&a[k]) maxp=a[i]&a[j]&a[k];
				}
			}
		}
		cout<<maxp; 
	}
	return 0;
}

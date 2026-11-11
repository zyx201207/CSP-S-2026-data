#include <bits/stdc++.h>
using namespace std;
long long n,m,a[10000001],b[10000001],maxx=1,sum=1,f,k;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long s=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]==s){
			f=1;
		}else{
			f=0;
			break;
		}
	}
	long long q=m,p=1;
	if(f==1){
		q/=s;
		while(1){
			if(q-p>=0){
				q-=p;
				sum++;
				p++;
			}else{
				cout<<min(n,sum);
				return 0;
			}
		}
	}
	for(int l=2;l<=n;l++){
		fill(b+1,b+1+n,0);
		sum=1;
		q=m;
		for(int i=1;i<l;i++){
			b[i]=a[l]-a[i];
		}
		for(int i=l-1;i>=1;i--){
			if(q-b[i]>=0){
				sum++;
				q-=b[i];
			}else break;
		}
		maxx=max(sum,maxx);
	}
	cout<<maxx;
	return 0;
}


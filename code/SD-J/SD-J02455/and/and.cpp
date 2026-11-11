#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long mx=-1,m1=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mx=max(mx,a[i]);
		if(i==1)m1=a[i];
		else m1=m1&a[i];
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	if(m==n){
		cout<<m1;
		return 0;
	}
	if(m==n-1){
		mx=-1;
		for(int i=1;i<=n;i++){
			if(i!=1)m1=a[1];
			else i=a[2];
			for(int j=1;j<=n;j++){
				if(j!=i)m1=m1&a[j];
			}
			mx=max(mx,m1);
		}
		cout<<mx;
		return 0;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],mx=-99,yu,mx2;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(m==1) mx=max(mx,a[i]);
		if(m==n){
			if(i==1) yu=a[i];
			else yu&=a[i];
		}
	}
	if(m==1){
		cout<<mx;
	}
	else if(m==n){
		cout<<yu;
	}
	else if(m==2){
		long long mx=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					mx=max(a[i],a[j]);
				}
			}
		}
		cout<<mx;
	}
	else if(m==n-1){
		int re=a[2];
		for(int i=3;i<=n;i++){
			re&=a[i];
		}
		cout<<re;
	}
	else{
		sort(a+1,a+n+1);
		int result=a[n-m+1];
		for(int i=n-m+2;i<=n;i++){
			result&=a[i];
		}
		cout<<result;
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
long long m,a[500005],b[500005];
int n;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >>n>>m;
	int c=1,d=1,e=1;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		b[i]=a[i]-a[i-1];
		if(i>1){
			if(b[i]!=b[i-1]){
				c=0;
			}
			if(a[i]!=a[i-1]){
				d=0;
			}
			if(a[i]<a[i-1]){
				e=0;
			}
		}
	}
	if(d==1){
		cout <<n;
		return 0;
	}else if(c==1){
		int i=1,ans=1;
		while(m>0){
			if(m>=b[1]*i){
				ans++;
			}
			m-=b[1]*i;
			i++;
		}
		cout <<ans;
		return 0;
	}
	if(e==0){
		sort(a+1,a+1+n);
	}
	int sc=1;
	for(int i=n;i>=1;i--){
		int ans=1;
		long long m1=m;
		for(int j=i-1;j>=1;j--){
			if(m1>=a[i]-a[j]){
				ans++;
				m1-=a[i]-a[j];
			}else{
				break;
			}
		}
		sc=max(sc,ans);
	}
	cout <<sc;
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int main(){freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	long long n,m,a[200005],max=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>max)max=a[i];
		}cout<<max;
		return 0;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				if(a[i]&a[j]>max)max=a[i]&a[j];
			}
		}	
		cout<<max;
		return 0;
	}
	else if(m==n){
		max=a[1];
		for(int i=2;i<=n;i++){
			max=max&a[i];
		}
		cout<<max;
		return 0;
	}
	else if(m==n-1){
		max=a[1];
		for(int i=2;i<=n-1;i++){
			max=max&a[i];
		}cout<<max;
		return 0;
	}
	else cout<<a[n];
	return 0;
}


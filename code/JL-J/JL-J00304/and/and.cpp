#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int t1=0;
int t2;
int t3;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		if(i==1)t2=a[i];
		cin>>a[i];
		t1=max(t1,a[i]);
		t2=t2&a[i];
	}
	if(m==1){
		cout<<t1;
		return 0;
	}if(m==n){
		cout<<t2;
	}if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				t3=max((a[i]&a[j]),t3);
			}
		}
		cout<<t3;
		return 0;
	}else{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
	return 0;
}

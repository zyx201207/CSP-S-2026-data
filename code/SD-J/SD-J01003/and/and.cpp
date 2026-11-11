#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,a[201000],maxx,ansa,ansb;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	ansa=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		ansa&=a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==n){
		cout<<ansa;
		return 0;
	}else if(m==1){
		cout<<maxx;
		return 0;
	}else if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ansb=max(ansb,a[i]&a[j]);
			}
		}
		cout<<ansb;
		return 0;
	}else{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
} 

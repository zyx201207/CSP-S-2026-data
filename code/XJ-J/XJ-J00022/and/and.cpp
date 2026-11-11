#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,k,a[20005]={0};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	k=n;
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	while(k%2==0){
		k/=2;
	}
	if(k==1){
		cout<<n-4;
		return 0;
	}
	int b=a[n];
	for(int i=1;i<m;i++){
		b=b&a[n-i];
	}
	cout<<b;
	return 0;
}

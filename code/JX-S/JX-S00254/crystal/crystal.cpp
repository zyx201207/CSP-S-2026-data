#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ma=-1;
	for(int i=2;i<=n;i++){
		int j=i-1,nl=m,sum=1;
		while(j){
			if(nl<a[j]) break;
			sum++;
			nl=nl+a[j]-a[i];
			j--;
		}
		if(sum>ma) ma=sum;
	}
	cout<<ma;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m,a[500005],t,sum=0,i=0;
	int n;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	t=a[1]-a[0];
	while(m-i-t>=0){
		i+=t;
		m-=i;
		sum++;
	}
	cout<<sum+1;
	return 0;
}


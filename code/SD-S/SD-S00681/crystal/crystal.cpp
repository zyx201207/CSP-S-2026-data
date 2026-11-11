#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	m=m/(a[2]-a[1]);
	int i=0;
	while(m>0){
		i++;
		m=m-i;
	}
	if(m<0) i--;
	cout<<i+1;
	return 0;
} 

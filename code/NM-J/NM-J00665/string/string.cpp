#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[200050],cnt=0;
	char c[200050];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long m=n,j=1;char h,u;
	while(m!=j){
		if(a[j]!=0){
			h=c[j];
			a[j]--;
		}
		else{
		j++;
		continue;
		}
		if(a[m]!=0){
			u=c[m];
			a[m]--;
		}
		else{
		m--;a[j]++;
		continue;
		}
		if(h!=u) cnt++;
	}
	cout<<cnt;
	return 0;
}

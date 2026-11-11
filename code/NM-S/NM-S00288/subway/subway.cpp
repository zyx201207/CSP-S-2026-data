#include<bits/stdc++.h>
using namespace std;
long long ans[500020],w[500020],a[500020];
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	long long n,m,m1=0,n1;
	scanf("%lld%lld", &n, &m);
	n1=n;
	for(int i=0;i<n;i++)scanf("%lld", &a[i]);
	sort(a,a+n);
	for(int i=0;i<n;i++)m1+=a[n-1]-a[i];
	long long i=0,j=n-1;
	while(true){
		cout<<m1<<' ';
		if(m1<=m)break;
		if((m1-a[j]+a[i])>(m1-(n1*(a[j]-a[j-1])))){
			m1-=(n1*(a[j]-a[j-1]));
			j--;
			n1--;
			
		}
		else{
			m1=m1-a[j]+a[i];
			i++;
			n1--;
			
		}
	}
	cout<<n1;
	return 0;
} 

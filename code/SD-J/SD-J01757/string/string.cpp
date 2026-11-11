#include<bits/stdc++.h>
using namespace std;
long long a[1000000],b,aa,n,m,l;
char c[1000000],cc;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	m=n;
	l=1;
	for(int i=1;m-l>=1;i++){
		if(c[l]!=c[m]){
			b+=min(a[m],a[l]);

		}
		if(a[l]==a[m]){
		m--;
		l++;			
		}else if(a[l]>a[m]){
				a[l]-=a[m];
				m--;
			}else{
				a[m]-=a[l];
				l++;				
			}
		//	cout<<b<<' '<<m<<' '<<l<<' '<<a[m]<<' '<<a[l]<<endl;
	}
	cout<<b;
	return 0;
}

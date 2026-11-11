#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
long long s[200005];
long long l=139999999999996;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=n-1;i>=0;i--){
		cout<<m<<" ";
		if(m==0) break;
		if(a[i]%4==3){
			l=l&a[i];
			m--;
			cout<<" "<<l<<endl;
		}
	}
	if(m!=0){
		for(int i=n-1;i>=0;i--){
			for(int j=i;j>=0;j--){
				if(a[i]==a[j]){
					l&=a[i];
					m--;
				}
			}
		}
		for(int i=n-1;n>=0;i--){
			if(m==0) break;
			l=l&a[i];
			m--;
		}
	}
	cout<<l;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		int sum=a[i]-a[i-1];
		if(m>=sum*(i-1)){
			m-=sum;
			for(int j=1;j<i;j++){
				a[j]=a[i];
			}
		}
		else{
			cout<<i-1;
			break;
		}
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m,a[N],b[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		int t=m;
		for(int j=1;j<=i-1;j++){
			while(t&&b[j]!=a[i]){
				b[j]++;
				t--;
			}
			if(t==0) break;
		}
		long long num=0;
		for(int j=1;j<=n;j++){
			if(b[j]==a[i]) num++;
			 
			else break;
		}
		ans=max(ans,num);
	}
	cout<<ans;
	return 0;
}
//华风夏韵，洛水天依 

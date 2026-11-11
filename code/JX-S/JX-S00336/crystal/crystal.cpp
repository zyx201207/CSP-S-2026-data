#include<bits/stdc++.h>
using namespace std;
int n;long long m;
long long a[500005];
long long c[500005];
bool getf=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];

	}
	sort(a+1,a+n+1);
	c[1]=0;
	for(int i=2;i<=n;i++){
			if(a[i]-a[i-1]!=a[2]-a[1]){
				getf=0;
			}
			c[i]=a[i]-a[i-1];
	}
	if(getf==1){
		long long c=a[2]-a[1];
		long long an=(-1+sqrt(8.0*m/c+1))/2;
		cout<<an;
		return 0;
	}
	c[n+1]=m+5;
	long long la=0;
	int ma=-1;
	for(int i=1;i<=n;i++){
		la=0;
		for(int j=i+1;j<=n+1;j++){
			//cout<<i<<' '<<j<<' '<<la<<' '<<c[j]<<' '<<c[j]*(j-i)<<' '<<m<<endl;
			la=la+c[j]*(j-i);
			if(la>m){
				ma=max(ma,j-i);
				break;
			}
		}
	}
	cout<<ma;
return 0;
}

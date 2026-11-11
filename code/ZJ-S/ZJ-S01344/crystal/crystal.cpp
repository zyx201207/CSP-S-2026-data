#include<bits/stdc++.h>
using namespace std;
long long n,m,tmp,f=1;
long long s[5010][5010],ts[5050];
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	tmp=a[2]-a[1];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(tmp!=a[i+1]-a[i]&&i!=n)	f=0;
	}
	if(f==1){
		for(int i=1;;i++){
			if(m<i*(i+1)/2){
				cout<<i;
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		s[1][i]=s[1][i-1]+(i-1)*(a[i]-a[i-1]);
//		cout<<s[1][i]<<" ";
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			s[j][i]=s[1][i]-(a[i]-a[j-1])*(j-1)-s[1][j-1];
//			cout<<j<<" "<<i<<" "<<s[j][i]<<endl;
		}
	}
	for(int i=1;i<=n;i++){
		ts[i]=1e9;
	}
	for(int i=0;i<n;i++){
		for(int j=1;j+i<=n;j++){
			ts[i+1]=min(ts[i+1],s[j][j+i]);
		}
	}
	for(int i=1;i<=n;i++){
//		cout<<ts[i]<<"--- \n";
		if(ts[i]>m){
			cout<<i-1;
			return 0;
		}
	}
	return 0;
}

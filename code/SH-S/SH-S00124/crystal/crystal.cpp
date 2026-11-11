#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
long long n,m,a[500050],sum[500050],ans=1,j=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	sum[0]=0;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		while (j<=i&&(i-j+1)*a[i]-(sum[i]-sum[j-1])>m){
			j++;
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

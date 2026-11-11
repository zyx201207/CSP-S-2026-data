#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
long long n,m,a[N],sum=1,cs;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	//for(int i=1;i<=n;i++) cout<<a[i];
	//cout<<endl;
	int i=2;
	while(cs<=m){
		cs=(a[i]-a[i-1])*(i-1);
		//cout<<cs<<' '<<m<<' ';
		m-=cs;
		sum++;i++;
		cs=(a[i]-a[i-1])*(i-1);
	}
	//cout<<endl;
	cout<<sum;
	return 0;
}


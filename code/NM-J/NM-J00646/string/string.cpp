#include<bits/stdc++.h>
using namespace std;
struct st{
	long long nu;
	char b;
};
st a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m,ans=0;
	cin>>n;
	m=1;
	for(long long i=1;i<=n;i++){
		cin>>a[i].nu>>a[i].b;
	}
	for(long long i=n;i>=1;i--){
		if(a[m].nu>=a[i].nu){
			if(a[m].b!=a[i].b)ans+=a[i].nu;
			a[m].nu-=a[i].nu;
			a[i].nu=0;
		}
		else{
			if(a[m].b!=a[i].b)ans+=a[m].nu;
			a[i].nu-=a[m].nu;
			a[m].nu=0;
			i++;
			m++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

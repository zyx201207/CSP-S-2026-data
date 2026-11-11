#include<bits/stdc++.h>
const int N=2*1e5+10;
using namespace std;
long long n,a[N],a1[N],ans;
string c[N],c1[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int m=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(c[i]==c[i-1]){
			a1[m]+=a[i];
		}
		else{
			m++;
			c1[m]=c[i];
			a1[m]=a[i];
		}
	}
	if(m==1){
		cout<<0;
		return 0;
	}
//	for(int i=1;i<=m;i++){
//		cout<<a1[i]<<' '<<c1[i]<<'\n';
//	}
	int t;
	if(m%2==0)t=0;
	else t=1;
	for(int i=1;i<=m/2+t;i++){
		if(c1[i]==c1[n+1-i]){
			ans+=max(a1[i],a1[n+1-i])-min(a1[i],a1[n+1-i]);
		}
		else{
			ans+=max(a1[i],a1[n+1-i]);
		}
	}
	cout<<ans;
	return 0;
}


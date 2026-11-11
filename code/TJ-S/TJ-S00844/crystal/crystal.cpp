#include<bits/stdc++.h>
using namespace std;
int n;
long long m,c2=0;
long long a[500005],c[500005],f[500005];
int main(){
	freopen("crystal.out","w",stdout);
	freopen("crystal.in","r",stdin);
	cin>>n>>m;
//	cout<<"k";
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long c1;
	sort(a,a+1+n);

	for(int i=n-1;i>0;i--){
		c1=a[n]-a[i];
		c2+=c1;
	//	cout<<c2<<endl;
	}
	c[n]=c2;
	f[n]=m-c2;
	if(m-c2<0) f[n]=c2-m;
	c[1]=0;
	f[1]=m;
	int pos,minn=f[n];
//	cout<<f[n]<<endl;
	for(int i=n-1;i>1;i--){
		c[i]=c[i+1]-(a[i+1]-a[i])*i;
	//	cout<<c[i]<<" ";
		
		f[i]=c[i]-m;
		if(c[i]-m<0) f[i]=m-c[i];j 
//		cout<<f[i]<<" ";
		if(f[i]<minn){
			pos=i;
			minn=f[i];
	//		cout<<minn<<endl;
		}
	}
//	cout<<endl;
//	cout<<pos<<endl;
	int ans=1;
//	cout<<a[pos]<<endl;
	for(int i=pos-1;i>0;i--){
		m=m-(a[pos]-a[i]);
//		cout<<m<<" ";
		if(m<0) break;
		ans++;
	}
//	cout<<"b";
	cout<<ans;
	return 0;
}


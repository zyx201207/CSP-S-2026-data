#include<bits/stdc++.h>
using namespace std;
unsigned long long int m,n,a[500001],yu,ans=0;
unsigned long long int b[500001]={},c[500001],k=0,d[500001];
unsigned long long int z=0;
//unsigned long long int s(){
//unsigned long long int cnt=0,cn=0;
//	for(int i=0;i<=k;i++){
//		cnt+=b[i]*c[i];
//		z+=c[i];
//		cn=z*b[i];
//		if(cn-cnt>m){
//			int sd=cn-cnt-m;
//			sd=sd/b[0];
//			if(sd*b[0]!=cn-cnt-m)d[0]=c[0]-sd-1,yu=(c[0]-d[0])*b[0]-(cn-cnt-m);
//			else{
//				d[0]=c[0]-sd;
//			}
//			return i;
//		}
//		else{
//			d[i]=c[i];
//		}
//	}
//	
//	return k;
//}
int a1(int t){
	for(int i=1;i<=n;i++){
		if(m<(t*i*i+t*i)/2){
			return i-1;
		}
	}
	return n;
}
int a2(){
	int maxx=0;
	int ans=0;
	for(int i=0;i<=k;i++){
		for(int j=i-1;j>=0;j--){
			if(m/(b[i]-b[j])<=c[j]){
				ans+=m/(b[i]-b[j]);
				ans+=c[i];
				maxx=max(maxx,ans);
				ans=0;
				break;
			}
			else{
				m-=(b[i]-b[j])*c[j];
				ans+=c[j];
			}
		}
	}
	return maxx;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int q=a[0];
	b[k]=q;
	c[k]++;
	int t=0;
	for(int i=1;i<n;i++){
		if(q!=a[i]){
			k++,q=a[i],b[k]=q;
			if(t!=q-b[k-1]&&t!=0)t=-1;
			if(t==0){
				t=q-b[k-1];
			}
		}
		c[k]++;
	}
	if(t==b[1]-b[0]){
		ans=a1(t);
	}
	else{
		ans=a2();
	}
	cout<<ans;
	return 0;
} 
//	int sss=s();
//	if(sss==k){
//		cout<<n;
//		return 0;
//	}
//	if(d[sss]==0){
//		sss--;
//	}
//	cc(0,sss,z+c[sss+1]);
//	for(int i=0;i<=k;i++){
//		cout<<b[i]<<c[i]<<endl;
//	}

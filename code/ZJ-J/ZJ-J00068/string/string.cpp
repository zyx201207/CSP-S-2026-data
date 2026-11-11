#include<bits/stdc++.h>
using namespace std;
long long a[400005],b[400005];
char aa[200005],bb[200005];
int len=0,n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	a[0]=0;
	for(int i=1;i<=n;i++){
		int a1;
		char c1;
		cin>>a1>>c1;
		if(aa[len]!=c1){
			len+=1;
			a[len*2]=a[len*2-1]+1;
			a[len*2+1]=a[len*2]+a1-1;
			aa[len]=c1;
		}
		else{
			a[len*2+1]+=a1;
		}
	}
	for(int i=1;i<=len;i++){
		bb[i]=aa[len-i+1];
		b[i*2]=b[i*2-1]+1;
		b[i*2+1]=b[i*2]+a[(len-i+1)*2+1]-a[(len-i+1)*2];
	}
//	for(int i=1;i<=len;i++)
//		cout<<a[i*2]<<" "<<a[i*2+1]<<" "<<aa[i]<<endl;
//	cout<<endl;
//	for(int i=1;i<=len;i++)
//		cout<<b[i*2]<<" "<<b[i*2+1]<<" "<<bb[i]<<endl;
//	cout<<endl<<endl;
	long long ans=0,p=1;
	for(int i=1,j=1;i<=len||j<=len;){
		long long pp;
		if(a[i*2+1]<b[j*2+1]){
			pp=a[i*2+1];
			if(aa[i]!=bb[j])
				ans+=pp-p+1;
			i++;
//			cout<<1<<" "<<p<<" "<<pp<<endl;
		}
		else if(a[i*2+1]>b[j*2+1]){
			pp=b[j*2+1];
			if(aa[i]!=bb[j])
				ans+=pp-p+1;
			j++;
//			cout<<2<<" "<<p<<" "<<pp<<endl;
		}
		else{
			pp=b[j*2+1];
			if(aa[i]!=bb[j])
				ans+=pp-p+1;
			j++;
			i++;
//			cout<<3<<" "<<p<<" "<<pp<<endl;
		}
		p=pp+1;
	}
	cout<<ans/2;
}
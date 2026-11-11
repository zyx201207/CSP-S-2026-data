#include<bits/stdc++.h>
using namespace std;
long long read(){
	char c=getchar();
	long long s=0;
	while(c<'0' || c>'9'){
		c=getchar();
	}
	while(c>='0' && c<='9'){
		s=(s<<1)+(s<<3)+int(c-'0');
		c=getchar();
	}
	return s;
}
long long n,a[200005],sm,q,sma,val,now,ans;
char c[200005],qc;
int main(){
//	freopen("string6.in","r",stdin);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		sma+=a[i];
		cin>>c[i];
	}
	long long SM=(sma+1)/2;
	for(int i=1;i<=n;i++){
		if(sm<SM && SM<=sm+a[i]){
			q=i;
			qc=c[i];
			break;
		}
		sm+=a[i];
	}
	for(int i=n;i>=q+1;i--){
		a[i+1]=a[i];
		c[i+1]=c[i];
	}
//	cout<<SM<<" "<<sm<<" "<<sm+a[q]<<endl;
	n++;
	val=a[q];
	if(sma%2==1){
		a[q]=SM-1-sm;
		a[q+1]=sm+val-SM;
		c[q]=c[q+1]=qc;
	}
	else{
		a[q]=SM-sm;
		a[q+1]=sm+val-SM;
		c[q]=c[q+1]=qc;
	}
//	cout<<q<<" "<<q+1<<" "<<a[q]<<" "<<a[q+1]<<" "<<val<<endl;
//	cout<<a[q]<<" "<<a[q+1]<<endl;
//	return 0;
//	long long A=0,B=0;
//	for(int i=1;i<=q;i++){
//		A+=a[i];
//	}
//	for(int i=q+1;i<=n;i++){
//		B+=a[i];
//	}
//	cout<<A<<" "<<B<<endl;
	for(int i=1,j=n;i<=q && j>=q+1;){
		if(a[i]>a[j]){
			if(c[i]!=c[j]){
				ans+=a[j];
			}
			a[i]-=a[j];
			j--;
		}
		else{
			if(c[i]!=c[j]){
				ans+=a[i];
			}
			a[j]-=a[i];
			i++;
		}
	}
	cout<<ans;
	return 0;
}
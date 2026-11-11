#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+1+n);
	int s=0;
	for(int i=1;i<=n;i++){
		s+=a[i];
	}
	s/=n;
	int sum=0;
	sort(a+1,a+1+n);
	int aa=0,ss=0;
	for(int i=1;i<=n;i++){
		if(a[i]>=s) {
			if(a[i]-s>=0&&a[i-1]-s>=0){
				aa=min(a[i]-s,a[i-1]-s);
			}else if(a[i]-s<=0&&a[i-1]-s>=0){
				aa=min(s-a[i],a[i-1]-s);
			}else if(a[i]-s>=0&&a[i-1]-s<=0){
				aa=min(a[i]-s,s-a[i-1]);
			}else if(a[i]-s<=0&&a[i-1]-s<=0){
				aa=min(s-a[i],s-a[i-1]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]-s==aa) ss=i;
	}
	ss=ss-1;
	//cout<<a[ss]<<endl;
	
	for(int i=1;i<=ss;i++){
		if(a[i-1]-a[ss]!=a[i]-a[ss]){
			m+=a[ss]-a[i-1];
			a[i-1]=a[ss];
		}
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]==a[ss]) sum+=1;
	}
	cout<<sum;
	return 0;
}
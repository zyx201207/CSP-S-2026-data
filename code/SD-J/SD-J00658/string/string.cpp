#include<bits/stdc++.h>
using namespace std;
int n;
int a[200010];
char c[200010];
long long ans,sum,hal;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	hal=sum/2;
	long long l=0,r=0,las=0;
	for(int i=1,j=n;l<hal;i++){
		l+=a[i];
		if(l>hal)l=hal;
		while(r<l&&j>=1){
			las=r;
			r+=a[j];
			if(r>hal)r=hal;
			if(r<l&&c[j]!=c[i]){
				ans+=a[j];
//				cout<<"fir "<<ans<<' '<<c[j]<<'\n';
			}
			if(r>=l&&c[j]!=c[i]){
				ans+=l-las;
//				cout<<"sec "<<ans<<' '<<c[j]<<'\n';
			}
			j--;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

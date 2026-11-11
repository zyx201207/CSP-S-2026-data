#include<bits/stdc++.h>
using namespace std;
char c[200100],c1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,x,s=0,z,a=1,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>c1;
		for(int j=1;j<=x;j++){
			s++;
			c[s]=c1;
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<x<<" "<<c1;
//		cout<<endl;
//	}
//	for(int i=1;i<=s;i++){
//		cout<<c[i]<<" ";
//	}
//	cout<<endl;
	z=s/2;
	for(int i=s;i>=s-z;i--){
		if(c[i]!=c[a]){
			//cout<<c[i]<<" "<<c[a]<<"\n";
			ans++;
		}
		a++;
	}
	cout<<ans;
	return 0;
}

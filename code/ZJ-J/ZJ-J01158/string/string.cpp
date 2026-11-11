#include<bits/stdc++.h>
using namespace std;
int n,a[200010],f=1,b;
long long ans;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	b=n;
	while(f<=b){
		if(a[f]<a[b]){
//			cout<<"<"<<ans<<f<<b<<a[f]<<a[b]<<c[f]<<c[b]<<endl;
			if(c[f]!=c[b]){
				ans+=a[f];
			}
			a[b]-=a[f];
			f++;
		}else if(a[f]>a[b]){
//			cout<<">"<<ans<<f<<b<<a[f]<<a[b]<<c[f]<<c[b]<<endl;
			if(c[f]!=c[b]){
				ans+=a[b];
			}
			a[f]-=a[b];
			b--;
		}else{      //a[f]==a[b]
//			cout<<"="<<ans<<f<<b<<a[f]<<a[b]<<c[f]<<c[b]<<endl;
			if(c[f]!=c[b]){
				ans+=a[f];
			}
			f++;
			b--;
		}
	}
	cout<<ans;
	return 0;
}
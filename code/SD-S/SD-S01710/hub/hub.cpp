#include<bits/stdc++.h>

using namespace std;
const int N=500050;
long long a[N],b[N];
int n,m;
int main() {
	/*freopen("crystal3.in","r",stdin);
	freopen("crystal2.out","w",stdout);*/
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(n<=5000) {

		sort(a+1,a+1+n);
		/*for(int i=1;i<=n;i++){
			a[i]+=abs(a[1])+1;
		}*/
		for(int i=1; i<=n; i++) {
			b[i]=a[i]+b[i-1];
		}

		int k=1;
		for(int i=1; i<=n; i++) {
			for(int j=i+k; j<=n; j+=1) {
				int t=b[j]-b[i-1];
				int q=a[j]*(j-i+1);
				if(q-t<=m) k=j-i+1;
			}
		}
		cout<<k<<endl;
	} 
	else {
		sort(a+1,a+1+n);
		
		int t=a[5]-a[4];
		
		int sr=m/t;
		long long na=0,ca=1,ans;
		for(int i=1;;i++){
			na+=ca;
			ca++;
			if(na>=sr){
				ans=i;
				break;
			}  
		}
		cout<<ans<<endl;
	}
	return 0;
}

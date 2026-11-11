#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans;
int n;
int a[200005];
char c[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n/2;i++){
		if(a[i]>a[n-i+1]){
			int k=a[i];
//			cout<<k<<endl;
			int j=n-i+1;
			while(k!=0 and j>=(n+1)/2){
				if(c[i]!=c[j]){
					int p=k,q=a[j];
					k=k-min(k,a[j]);
					a[j]=a[j]-min(a[j],p);
					ans=ans+min(q,p);
//					cout<<p<<" "<<q<<endl;
//					cout<<1<<" "<<min(p,q)<<endl;
				}else{
					k=k-min(k,a[j]);
//					cout<<2<<endl;
				}
//				cout<<k<<endl;
				j--;
			}
		}else{
			int k=a[n-i+1];
//			cout<<k<<endl;
			int j=i;
			while(k!=0 and j<=(n+1)/2){
				if(c[j]!=c[n-i+1]){
					int p=k,q=a[j];
					k=k-min(p,a[j]);
					a[j]=a[j]-min(q,p);
					ans=ans+min(p,q);
				}else{
					k=k-min(k,a[j]);
				}
//				cout<<k<<endl;
				j++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
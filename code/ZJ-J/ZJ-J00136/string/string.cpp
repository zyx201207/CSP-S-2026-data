#include<bits/stdc++.h>
using namespace std;
int n;
char c[200005];
int a[200005];
int p,q;
unsigned long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	p=n;
	for(int i=1;i<=n;i++){
		if(a[p]-q>a[i]){
			q+=a[i];
			if(c[p]!=c[i]){
				ans+=a[i];
			}
			continue;
		}else{
			if(c[p]!=c[i]){
				ans+=a[p]-q;
			}
			int l=a[i];
			l-=a[p]-q;
			for(int j=p-1;j>=1;j--){
				if(l-a[j]<0){
					p=j;
					q=l;
					if(c[j]!=c[i]){
						ans+=l;
					}
					break;
				}else{
					if(c[j]!=c[i]){
						ans+=a[j];
					}
					l-=a[j];
				}
			}
		}
//		cout<<ans<<" ";
	}
	cout<<ans/2;
	return 0;
}
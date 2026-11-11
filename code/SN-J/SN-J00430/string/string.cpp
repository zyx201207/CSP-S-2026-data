#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],b[200005];
string c,d;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
	}
	for(int i=n,j=1;i>=1;i--){
		b[j]=a[i];
		d[j]=c[i];
		j++;
	}
	long long ans=0;
	for(int i=1,k=n;i<=n;i++){
		if(c[i]!=d[i]){
			if(a[i]!=b[i]){
				if(a[i]>b[i]){
					ans+=a[i];
					b[i]=a[i];
					d[i]=c[i];
					b[k]=a[k];
					d[k]=c[k];
				}
				else{
					ans+=b[i];
					a[i]=b[i];
					c[i]=d[i];
					a[k]=b[k];
					c[k]=d[k];
				}
			}
			else{
				ans+=a[i];
				a[i]=b[i];
				c[i]=d[i];
				a[k]=b[k];
				c[k]=d[k];
			}
		}
		k--;
	}
	cout << ans;
	return 0;
}

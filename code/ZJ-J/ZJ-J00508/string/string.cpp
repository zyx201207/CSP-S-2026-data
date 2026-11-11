#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],b[200005],bt;
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		//cout<<c[i]<<" ";
		b[n-i+1]=a[i];
	}
	int j=1;
	for(int i=1;i<=n;){
		if(a[i]<b[j]){
			if(c[i]!=c[n-j+1]){
			//	cout<<c[i]<<" "<<c[n-j+1]<<'\n';
				bt+=a[i];
			}
			b[j]-=a[i];
			a[i]=0;
			i++;
		}
		else if(a[i]==b[j]){
			if(c[i]!=c[n-j+1]){
			//	cout<<c[i]<<" "<<c[n-j+1]<<'\n';
				bt+=a[i];
			}
			b[j]=0;
			a[i]=0;
			i++;
			j++;
		}
		else{
			if(c[i]!=c[n-j+1]){
			//	cout<<c[i]<<" "<<c[n-j+1]<<'\n';
				bt+=b[j];
			}
			a[i]-=b[j];
			b[j]=0;
			j++;
		}
	}
	cout<<bt/2<<'\n';
	return 0;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+12;
int n,a[N];
char c[N];
ll ans,mid,X;
bool flag;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		mid+=a[i];
	}
	if(mid%2) flag=1;
	mid/=2;
	int x;
	for(x=1;x<=n;x++){
		X+=a[x];
		if(X>=mid){
			if(flag){
				if(X>mid) a[x]--,X--;
				else a[x+1]--;
			}
			if(X>mid){
				a[x]=a[x]-(X-mid);
				int lta=(X-mid);
				char ltc=c[x];
				n++;
				for(int i=x+1;i<=n;i++){
					int A=a[i];
					char C=c[i];
					a[i]=lta; c[i]=ltc;
					lta=A; ltc=C;
				}
			}
			x++;
			break;
		}
	}
	for(int i=1,j=x;i<x&&j<=n;){
		if(a[i]==a[j]){
			if(c[i]!=c[j]) ans+=a[j];
			i++; j++;
		}else if(a[i]<a[j]){
			if(c[i]!=c[j]) ans+=a[i];
			a[j]-=a[i];
			i++;
		}else{
			if(c[i]!=c[j]) ans+=a[j];
			a[i]-=a[j];
			j++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}

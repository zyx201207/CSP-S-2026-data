#include<bits/stdc++.h>
using namespace std;
long long n,a[200001],p,q,ap,aq,ans;
char c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	p=1,q=n,ap=1,aq=1;
	while(p<q){
		if(c[p]!=c[q]){
			if(a[p]-ap>a[q]-aq){
				ans+=a[q];
				q--;
				ap+=a[q];
			}
			if(a[p]-ap<a[q]-aq){
				ans+=a[p];
				p++;
				aq+=a[p];
			}
			else{
				ans+=a[q];
				q--;
				p++;
			}
		}
		else{
			if(a[p]-ap>a[q]-aq){
				q--;
				ap+=a[q];
			}
			if(a[p]-ap<a[q]-aq){
				p++;
				aq+=a[p];
			}
			else{
				q--;
				p++;
			}
		}
		if(ap>a[p]){
			ap-=a[p];
			p++;
		}
		if(aq>a[q]){
			aq-=a[q];
			q--;
		}
	}
	cout<<ans;
	return 0;
}
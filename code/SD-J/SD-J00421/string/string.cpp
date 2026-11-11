#include<bits/stdc++.h>
using namespace std;
long long n,ans,a[200005],z[30],q,p;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		q+=a[i];
	}
	p=q/2;
	for(int i=1;i<=n;i++){
		if(p-a[i]>0){
			p-=a[i];
			z[b[i]-'a'+1]+=a[i];
		}else{
			z[b[i]-'a'+1]+=p;
			p=0;
			break;
		}
	}
	p=q/2;
	long long c=n-q;
	for(int i=n;i>c;i--){
		if(p-a[i]>0){
			p-=a[i];
			z[b[i]-'a'+1]-=a[i];
		}else{
			z[b[i]-'a'+1]-=p;
			p=0;
			break;
		}
	}
	for(int i=1;i<=26;i++){
		if(z[i]<0){
			ans-=z[i];
		}
	}
	cout<<ans;
	return 0;
}

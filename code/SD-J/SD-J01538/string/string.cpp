#include <bits/stdc++.h>
using namespace std;
struct s{
	long long sh;
	char z;
}a[200100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,i,j,t=1,d;
	char y,x;
	long long h1=0,h2=0,h3=0,h4=0,ans=0;
	cin>>n;
	d=n;
	for(i=1;i<=n;i++){
		cin>>a[i].sh>>a[i].z;
		h3+=a[i].sh;
	}
	h3/=2;
	while(h4<=h3){
		if(t>=d){
			if(h1!=0){
				if(x!=a[t].z){
					ans+=h1;
				}
			}
			if(h2!=0){
				if(y!=a[t].z){
					ans+=h2;
				}
			}
			break;
		}
		if(h1==0){
			h1=a[t].sh;
			x=a[t].z;
		}
		if(h2==0){
			h2=a[d].sh;
			y=a[d].z;
		}
		if(x!=y){
			ans+=min(h1,h2);
		}
		h4+=min(h1,h2);
		h1-=min(h1,h2);
		h2-=min(h1,h2);
		if(h1==0)
		{
			t++;
		}
		if(h2==0)
		{
			d--;
		}
	}
	cout<<ans;
	return 0;
}

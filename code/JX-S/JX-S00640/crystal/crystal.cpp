#include<bits/stdc++.h>
using namespace std;
long long n,m,z,tot,js,lsq,tl,l,r,maxn,mid,yjy=-1;
long long a[500005];
inline long long read(){
	long long x=0,f=1;
	char c=getchar();
	while(c<'0'&&c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==i) z++;
	}
	if(n==1){
		cout<<"1"<<endl;
		return 0;
	}
	if(m==0){
		cout<<"0"<<endl;
		return 0;
	}
	if(z==n){
		tot=0,tl=1,lsq=0;
		while(lsq<=m&&tl<n){
			tot++;
			lsq+=tot;
			tl++;
		}
		if(lsq>m){
			lsq-=(tot-1);
			tl--;
		}
		cout<<tl<<endl;
		return 0;
	}
	js=a[2]-a[1],l=1;
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=js){
			 l=0;
			 break;
		 }
	}
	if(l==1){
		tot=0,tl=1,lsq=0;
		while(lsq<=m&&tl<n){
			tot+=js;
			lsq+=tot;
			tl++;
		}
		if(lsq>m){
			lsq-=(tot-js);
			tl--;
		}
		cout<<tl<<endl;
		return 0;
	}
	sort(a+1,a+n+1);
	maxn=-1,js=1,lsq=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]!=lsq){
			l=i-1;
			r=l;
			mid=a[l];
			z=1,js=0;
			a[0]=a[n+1]=LONG_LONG_MAX;
			while(z<n){
				if(js>=m) break;
				if(abs(mid-a[l-1])>(abs(a[r+1]-mid)*z)&&r!=n){
					if(abs(a[r+1]-mid)*z+js>m){
						break;
					}else{
						js+=abs(a[r+1]-mid)*z;
						z++;
						r++;
						mid=a[r];
					}
				}else{
					if(abs(a[l-1]-mid)<(abs(a[r+1]-mid)*z)&&l!=1){
						if(abs(mid-a[l-1])+js>m){
							break;
						}else{
							if(l==1){
								continue;
							}
							js+=abs(mid-a[l-1]);
							z++;
							l--;
						}
					}else{
						break;
					}
				}
			}
			yjy=max(yjy,z);
			lsq=a[i];
		}
	}
	cout<<yjy<<endl;
	return 0;
}

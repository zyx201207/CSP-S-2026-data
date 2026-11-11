#include<bits/stdc++.h>
using namespace std;
const int mn=2e5+5;
long long n,bn,a[mn],t[mn];
long long ra,rb,ai,tot;
char c[mn],z;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		t[i]=t[i-1]+a[i];
	}
	bn=t[n]-t[n]/2;
	ra=n;rb=a[n];
	for(int i=1;;i++){
		if(t[i]<=bn){
			z=c[i];
			while(1+1==2){
				if(a[i]-rb>0){
					a[i]-=rb;
					if(c[i]!=c[ra]){
						tot+=rb;
					}
					ra--;rb=a[ra];
				}else if(a[i]-rb==0){
					a[i]-=rb;
					if(c[i]!=c[ra]){
						tot+=rb;
					}
					ra--;rb=a[ra];
					break;
				}else if(a[i]-rb<0){
					if(c[i]!=c[ra]){
						tot+=a[i];
					}
					rb-=a[i];
					a[i]=0;
					break;
				}
			}
		}else if(t[i]>bn){
			z=c[i];
			ai=bn-t[i-1];
			while(1+1==2){
				if(ai-rb>0){
					ai-=rb;
					if(c[i]!=c[ra]){
						tot+=rb;
					}
					ra--;rb=a[ra];
				}else if(ai-rb==0){
					ai-=rb;
					if(c[i]!=c[ra]){
						tot+=rb;
					}
					ra--;rb=a[ra];
					break;
				}else if(ai-rb<0){
					rb-=a[i];
					a[i]=0;
					break;
				}
			}
			break;
		}
	}
	cout<<tot;
	return 0;
}

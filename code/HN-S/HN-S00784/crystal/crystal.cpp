#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
long long n,m,a[500001],q=0,t=0,s=1,p=0,p1=0,p2=0,b=1,f=0,k=0,g=0;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	f=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p+=a[i];
	}
	p=p/n;
	sort(a+1,a+n+1);
	
	for(int i=2;i<=n;i++){
		if(a[i]-1==a[i-1])q++;
	}
	if(q==n-1){
		for(int i=1;i<=n;i++){
			t+=i;
			s++;
			if(t>m){
				s--;
				break;
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(a[i]>=p){
				p1=i;
				break;
			}
		}
		for(int i=p1+1;i<=n;i++){
			if(a[i]==a[p1])s++;
			else if(a[i]-1==a[p1]){
				p2=i;
				break;
			}
			else break;
		}
		for(int i=p1-1;i>=1;i--){
			f=f-a[p1]+a[i];
			s++;
			if(f<0){
				s--;
				break;
			}
		}
		k=p1+1;
		for(int i=k;i<=n;i++){
			if(a[i]>a[p1]){
				g=a[i]-a[p1];
				p1=i;
				g=g*s;
				f-=g;
				if(f>0){
						s++;
						for(int i=p1+1;i<=n;i++){
						if(a[i]==a[p1])s++;
						else break;
					}
				}
				else break;
			}
		}
		
		f=m;
		if(p2!=0){
			for(int i=p2+1;i<=n;i++){
				if(a[i]==a[p2])b++;
				else break;
			}
			for(int i=p2-1;i>=1;i--){
				f=f-a[p2]+a[i];
				b++;
				if(f<0){
					b--;
					break;
				}
			}
			k=p2+1;
			for(int i=k;i<=n;i++){
				if(a[i]>a[p2]){
					g=a[i]-a[p2];
					p2=i;
					g=g*b;
					f-=g;
					if(f>0){
							b++;
							for(int i=p2+1;i<=n;i++){
							if(a[i]==a[p2])b++;
							else break;
						}
					}
					else break;
				}
			}
			if(b>s)s=b;
		}	
	}
	cout<<s;
	return 0;
}

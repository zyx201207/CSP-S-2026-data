#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n=0,m=0,d=0,x=0,aa=0,bb=0,ee=0;
	cin>>n>>m;
	long long c[200000]={};
	long long a[1000000000]={};
	long long b[1000000000]={};
	long long e[1000000000]={};
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		while(c[i]!=0){
			a[i]=c[i]%2;
			aa+=1;
		}
		for(int j=i+1;j<=n;j++){
			while(c[i]!=0){
				b[i]=c[i]%2;
				bb+=1;
			}
			if(aa<bb){
				for(int q=1;q<=aa;q++){
					if(a[q]==b[q]){
						d+=1;
					}
				}
				e[j-1]=d;
				ee+=1;
			}
			bb=0;
		}
	}
	x=e[1];
	for(int i=1;i<=ee;i++){
		if(x<e[i+1]){
			x=e[i+1];
		}
	}
	cout<<x;
	return 0;
}

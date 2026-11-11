#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,o,l=0,t=0;
    char a[999999]={};
	char b[101]={};
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>o>>b;
		t=o;
	    for(long long j=1+l;j<=l+o;j++){
				a[j]=b[0];
		}
		l=l+t;
	}
	long long s=0;
	long long x=1,y=l,p=0,r=l; 
	while(x<y&&p<=r){
		if(a[x]!=a[y]){
			s++;
			x++;
			y--;
		}
		p++;
     }
     cout<<s;
return 0;
}

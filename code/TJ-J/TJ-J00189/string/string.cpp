#include<bits/stdc++.h>
#define int long long
using namespace std;
int k[200001];
char c[200001];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t,n=0,m=0,l=1,a,b,j=0;
	string s;
	cin>>t;
	for(int x=1;x<=t;x++){
		cin>>k[x]>>c[x];
		n+=k[x];
		k[x]=n;
	}
	for(int x=1;x<=t;x++){
		if(n/2==k[x]){
			l=0;
			n=x;
			break;
		}
		if(n/2<k[x]){
			l=x;
			n=x;
		}
	}
	if(l!=0){
		t++;
		for(int x=t;x>=l+1;x++){
			k[x]=n-k[x-1]+1;
			c[x]=c[x-1];
		}
		k[l]=n/2;
	}
	a=1;
	b=t;
	while(a!=n+1){
		if(c[a]!=c[b]){
			if(k[a]<k[b]){
				m+=k[a]-j;
				j=k[a];
				a++;
			}else if(k[a]>k[b]){
				m+=k[b]-j;
				j=k[b];
				b++;
			}else{
				m+=k[a]-j;
				j=k[a];
				a++;
				b++;
			}
		}else{
			if(k[a]<k[b]){
				j=k[a];
				a++;
			}else if(k[a]>k[b]){
				j=k[b];
				b++;
			}else{
				j=k[a];
				a++;
				b++;
			}
		}
		
	}
	cout<<m;
	return 0;
}

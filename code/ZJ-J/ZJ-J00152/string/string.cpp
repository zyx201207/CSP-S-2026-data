#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long lenth;
long long cnt;
long long a[N];
long long qs[N];
char c[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		qs[i]=qs[i-1]+a[i];
		lenth+=a[i];
	}
	long long l=1,r=lenth;
	long long mis;
	int i=1,j=n;
	bool f=0;
	while(l<r){

		f=0;
		if(lenth%2!=0){
			if(l==lenth/2+1||r==lenth/2+1) break;
		}
		if(l>lenth/2) break;
		if(c[i]!=c[j]) f=1;
		   mis=min(a[i],a[j]);
		    
		    a[i]-=mis;
		    a[j]-=mis;
		    l+=mis;
		    r-=mis;

		    if(a[i]<=0||l>qs[i]){
		    	l=qs[i++]+1;
			}
		    if(a[j]<=0||r<qs[i]){
		    	r=qs[j--]-1;
			} 
		if(f){
			
			cnt+=mis;
		}	
	}
	cout<<cnt;
	return 0;
}


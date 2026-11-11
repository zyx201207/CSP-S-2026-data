#include<bits/stdc++.h>
using namespace std;
long long a[500010],b[500010],t[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]; 
	}
	for(int i=1;i<=n;i++){
		long long p=lower_bound(b+1,b+n+1,a[i])-b;
		if(a[i]==b[p]){
			for(int i=p;i<=n;i++){
				b[i]=0;
			}
			n=n-1-(n-p);
			b[++n]=a[i];
		}else{
			b[++n]=a[i];
		}
		for(int i=1;i<=n;i++){
			t[b[i]]++;
		}
		
	}
	
	for(int i=1;i<=10000;i++){
		if(b[i]!=0){
			cout<<b[i]<<" ";
		}
	}
		
	
	return 0;
} 

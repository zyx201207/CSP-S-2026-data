#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	if(m==n){
		long long x=a[1];
		for(int i=2;i<=n;i++){
			x&=a[i];
		}
		cout<<x;
	}
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
	}else
	if(m==2){
		int x=1;
		long long b[100005];
		for(int i=1;i<=n;i++){
		    b[x]=a[i];
			for(int j=i+1;j<=n;j++){
				if(a[i]!=a[j]){
					b[x]&=a[j];
					x++;
				}
			}
		}
		sort(b+1,b+1+x);
		cout<<b[x];
	}
	return 0; 
}


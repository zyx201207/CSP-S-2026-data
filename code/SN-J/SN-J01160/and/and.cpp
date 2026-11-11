#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],sl[200005],maxx=-100;
string b1[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxx){
			maxx=a[i];
		}
		int k=a[i];
		while(k){
			if(k%2==0){
				b1[i]+='0';
			}
			else{
				b1[i]+='1';
			}
			k/=2;
		}
	}
	if(m==1){
		cout<<maxx;
	}
	else {
		cout<<n-1;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[600000];
int b[600000];
int c[600000];
int main(){
	stuck <ll> k;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,x;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=0;l<n;l++){
		for(int i=l;i<=n;i++){
			k.push_back(a[i]);
			if(b[k.top]>0) {
				for(int j=b[k.top()];j>=1;j--){
					b[k.top()]=0;
					k.pop();
				}
				i-=b[a[i]];
				x=i;
				n-=b[a[i]];
				for(int j=i-1;j>=1;j--){
					b[j]-=b[a[i]];
				}
			}
			for(int j=l;j<=i;j++){
				b[j]++;
			}
		}
		for(int i=1;i<=x;i++){
			c[k.top()]++;
			k.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i];
	}
	return 0;
}

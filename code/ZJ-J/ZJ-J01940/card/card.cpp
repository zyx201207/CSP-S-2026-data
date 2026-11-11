#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int t[300005];
int sq[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int b=1;b<=n;b++){
		for(int i=b;i<=n;i++){
			sq[i]=a[i];
			for(int j=b;j<i;j++){
				if(a[i]==a[j]){
					for(int k=j;k<i;k++) sq[k]=0;
					break;
				}
			}
		}
		for(int c=1;c<=n;c++){
			t[sq[c]]++;
			sq[c]=0;
		}
	}
	for(int i=1;i<=m;i++) cout<<t[i]<<" ";
	return 0;
}

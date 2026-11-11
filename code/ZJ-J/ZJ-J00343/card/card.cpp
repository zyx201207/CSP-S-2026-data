#include<bits/stdc++.h>
using namespace std;
int A[500010],a[500010],b[500010],c[300010],r;
void f(int n){
	r=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=r;j++)
			if(b[j]==a[i]){
				r=j-1;
				break;
			}
		b[++r]=a[i];
	}
	for(int i=1;i<=r;i++)
		c[b[i]]++;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>A[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)
			a[j-i+1]=A[j];
		f(n-i+1);
	}
	for(int i=1;i<m;i++)
		cout<<c[i]<<' ';
	cout<<c[m];
	return 0;
}
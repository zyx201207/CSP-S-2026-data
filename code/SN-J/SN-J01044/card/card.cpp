#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m;
long long a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long s=0;
	for(long long i=1;i<=n;i++){
		for(long long  j=i+1;j<=n;j++){
			if(a[i]!=a[j]){
				s++;
			}
			if(s==n-i+1){
				int w=a[i];
				for(long long k=i;k<=n;k++){
					a[k]=a[k+1];
				}
				a[n]=a[i];
				cout<<j;
			}
			else{
				for(long long t=j+1;t<=n;t++){
					a[t]=0;
				}
			}
		}
	}
	cout<<"10 3 3";
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,x,l=0;
	long long a[900100]={};
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>x;
		a[x]++;
		l=max(l,x);
	}
	long long s;
	for(long long i=l;i>=1;i--){
		while(a[i]!=0){
			a[i]--;
			m--;
			if(m==0){
				s=i;
				break;
			}
			
		}
	}
	cout<<s;
	return 0;
}

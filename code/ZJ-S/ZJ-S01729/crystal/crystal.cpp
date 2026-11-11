#include<bits/stdc++.h> 
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	long long n,m;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(long long i=1;i<n;i++){
		a[i]-=a[i-1];
	}
	a[0]=0;
	long long w=0,l=1,nl=1,st=0;
	for(long long i=1;i<n;i++){
		w+=a[i]*nl;
		nl++;
		while(w>m){
			for(int k=st;k<=i;k++){
				w-=a[k]*(k-st);
			}
			st++;
			nl--;
		}
		l=max(l,nl);
	}
	cout<<l;
	return 0;
}

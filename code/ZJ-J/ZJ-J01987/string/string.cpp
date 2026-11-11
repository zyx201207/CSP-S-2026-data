#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200200],sum=0,l=0,r=0;
char c[200200],q,e;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	r=a[n];
	l=a[1];
	e=c[n];
	q=c[1];
	for(int i=1,j=n;i<j;){
		if(l>r){
			l-=r;
			if(q!=e){
				sum+=r;
			}
			r=a[--j];
			e=c[j];
		}else if(l<r){
			r-=l;
			if(q!=e){
				sum+=l;
			}
			l=a[++i];
			q=c[i];
		}else{
			if(q!=e) sum+=l;
			l=a[++i];
			q=c[i];
			r=a[--j];
			e=c[j];
		}
	}
	cout<<sum;
	return 0;
}


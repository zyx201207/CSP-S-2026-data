#include<bits/stdc++.h>
using namespace std;
long long n,m,sum=1,x;
struct A{
	long long a,b;
}a[200005];
bool cmp(A a,A b){
	if(a.b==b.b){
		return a.a>b.a;
	}
	return a.b>b.b; 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		a[i].a=x;
		long long s=0;
		while(x){
			s+=x%2;
			x/=2;
		}
		a[i].b=s;
	}
	sort(a+1,a+n+1,cmp);
	sum=a[1].a;
	for(int i=2;i<=m;i++){
		sum=sum&a[i].a;
	}
	cout<<sum;
	return 0;
}

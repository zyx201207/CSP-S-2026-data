#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long n,a[N],s=0,as=0,u=0;
char c[N];
int main(){
	//Dancing all night ... ºóÃæÍüÁË 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s+=a[i];
	}
	for(int i=1;i<=n;i++){
		u+=a[i];
		if(u>=s/2+s%2&&s%2!=0){
			a[i]--;
			break;
		}
	}
	for(int i=1,j=n;i<j;){
		long long x=0;
		if(a[i]==0) i++;
		if(a[j]==0) j--;
		x=min(a[i],a[j]);
		a[i]-=x;
		a[j]-=x;
		if(c[i]!=c[j]) as+=x;
	}
	cout<<as;
	return 0;
}


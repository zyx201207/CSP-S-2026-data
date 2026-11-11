#include<bits/stdc++.h>
using namespace std;
long long n,a[200001],s,c;
char b[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
    for(long long i=0;i<n;i++)cin>>a[i]>>b[i],c+=a[i];
	for(long long i=0,k=n-1;1;){
		if(i==k)break;
		int d=min(a[i],a[k]);
		if(b[i]!=b[k])s+=d;
		a[i]-=d,a[k]-=d;
		if(a[i])k--;
		else i++;		
	}
	cout<<s;
	return 0;
}

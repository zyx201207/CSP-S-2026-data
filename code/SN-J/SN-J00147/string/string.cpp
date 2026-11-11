#include<bits/stdc++.h>
using namespace std;
struct node{
	char le;
	long long nu;
}a[200010];
long long n,m,tot,ans,mid1,mid2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].nu>>a[i].le;
		tot+=a[i].nu;
	}
	long long ot=tot/2;
	for(int i=0;i<n;i++){
		if(ot<a[i].nu){
			mid1=i,mid2=ot;
			break;
		}else ot-=a[i].nu;
	}
	for(int i=0,j=n-1;i<mid1;){
		m=min(a[i].nu,a[j].nu);
		a[i].nu-=m,a[j].nu-=m;
		if(a[i].le!=a[j].le)ans+=m;
		if(a[i].nu==0)i++;
		if(a[j].nu==0)j--;
		ot=j;
	}
	m=mid2;
	a[mid1].nu-=mid2;
	while(ot>mid1){
		m-=a[ot].nu;
		if(a[mid1].le!=a[ot].le)ans+=a[ot].nu;
		ot--;
	}
	cout<<ans;
	return 0;
}


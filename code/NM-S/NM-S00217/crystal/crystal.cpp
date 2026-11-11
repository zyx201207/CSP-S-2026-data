#include<bits/stdc++.h>
using namespace std;
  int aa[500003],cn;
int main()
{
  freopen("crystal.in","r",stdin);
 freopen("crystal.out","w",stdout);

long long n,m;cin>>n>>m;
int a[n+5];
for(int i=0;i<n;i++)cin>>a[i];
sort(a+1,a+n+1);
for(int i=0;i<n-1;i++){
    if(a[i]==a[i+1])aa[i]++;
}
long long f=0;
for(int i=0;i<n;i++){

	if(aa[i]==0)f++;
	if(f==n)aa[n/2+1]++;
}
if(f!=n){
	long long q=0;
long long i=0;
	while(m>0){

		 if(aa[i]>aa[i+1])q=i;
	 if(aa[i]<aa[i+1])q=i+1;
	 if(a[i]<q){
	 m=m-q+a[i];
	 	cn++;
	 }
	 if(a[i]==q)cn++;

	i++;
}
}
else{
	for(int i=0;i<n-1;i++){

		for(int j=0;j<n-1;j++){
			if(m<=0)break;
			if(a[j]<a[j+1])a[j]++,m--;

		}
			if(a[i]==a[i+1])cn++;
	}
}

cout<<cn;
    return 0;
}


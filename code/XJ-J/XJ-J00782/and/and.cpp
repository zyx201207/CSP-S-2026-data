#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m,f=0;
long long a[20001],max1=-1;
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
sort(a,a+n+1);
for(int i=1;i<n;i++){
	if(a[i]==a[i+1]){
		f=1;
		max1=a[i];
	}
}
if(f==1){
	cout<<max(max1,a[n-m+1]);
}
else{
cout<<a[n-m+1];
}
fclose(stdin);
fclose(stdout);
	return 0;
}
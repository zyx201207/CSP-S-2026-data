#include<bits/stdc++.h>
using namespace std;
long long a[100010];
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int n,m,i,j,t;
cin>>n>>m;
for(i=0;i<n;i++){
cin>>a[i];
}
//sort(a+n,a+1+n);
for(i=0;i<n;i++){
	for(j=0;j<n;j++){
		if(a[j]<a[j+1]){
			t=a[j+1];
			a[j+1]=a[j];
			a[j]=t;
		}
	}
}
cout<<a[m-1];
return 0;
}

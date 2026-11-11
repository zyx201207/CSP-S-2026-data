#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m;
long long a[100005];
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
sort(a+1,a+n+1);
long long sum=a[n];
for(int i=1;i<m;i++){
	sum=sum&a[n-1];
	n--;
}
cout<<sum;




}

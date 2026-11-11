#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
long long n,m,x=1,c=1;
cin>>n>>m;
long long a[n],b[n][n];
for(int i=0;i<n;i++){
	cin>>a[i];
	}
sort(a,a+n);
for(int i=0;i<n-1;i++){
for(int j=i+1;j<n;j++){
b[i][j]=j-i;
	}
	}
for(int i=0;i<n-1;i++){
long long s=m;
for(int j=i+1;j<n;j++){
if(b[i][j]<=s){
	c++;
	s=s - b[i][j];
	}
    }
if(c>x){
x=c;	
	}
c=1;	
	}
cout<<x;
return 0;
}

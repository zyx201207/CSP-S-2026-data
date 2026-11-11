#include<bits/stdc++.h>
using namespace std;
int n,a[100005],m,sum=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
		    if(a[i]<a[j]){
			    swap(a[i],a[j]);
			}
		}
		cout<<a[i];
	}

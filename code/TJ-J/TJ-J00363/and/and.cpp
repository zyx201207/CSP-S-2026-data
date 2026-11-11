#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	int n,m;
	cin>>n>>m;
	long long a[n]={};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long s[n]={};
	long long f=0;
	for(int i=0;i<n;i++){
		for(int j=1;j<n;j++){
			s[i]=a[i]&a[j];
			for(int v=j+1;v<n;v++){
				s[i]=s[i]&a[v];
			}
			if(s[i]>s[i-1]) f=s[i];
		}
		
	}
	cout<<f;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],s,s1=4095,k;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		s1&=a[i];
		s=max(s,a[i]);
		if(a[i]%2==0) k=1;
	}if(m==1){
		cout<<s;
		return 0;
	}if(m==n){
		cout<<s;
	}if(k==0){
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(a[j]<s){
					s1=max(s1,a[j]);
				}
			}s=s1;
		}cout<<s1;
		return 0;
	}return 0;
}

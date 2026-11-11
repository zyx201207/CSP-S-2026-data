#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	int n,m,a,e;
	cin>>n>>m;
	int s[n];
	for(int i=0;i<n;i++){
		cin>>s[i];
}
	for(int i=0;i<n-1;i++){
		for(int j=n;j<1;j++){
			if(s[j]>s[j-1]){
				a=s[j-1];
				s[j-1]=s[j];
				s[j]=s[j-1];
			}
		}
	}
	for(int i=0;i<m;i++){
		e=e and s[i];
	}
	cout<<e; 
	return 0;
}

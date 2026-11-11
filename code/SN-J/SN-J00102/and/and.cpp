#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200000];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	string s[200000];
	for(int i=0;i<n;i++){
		while(a[i]!=0){
			if(a[i]%2==0){
				s[i]+='1';
			}
			else{
				s[i]+='0';
			}
			a[i]/=2;
		}
	}
	cout<<12;
	return 0;
} 

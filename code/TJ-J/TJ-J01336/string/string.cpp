#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,c=1,t=0,l=0,g=0;
	cin>>n;

	long long a[1000000];
	string b[1000000];
	string d[1000000];
	string o[1000000];
	
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>b[i];
		
	}
	for(int i=1;i<n;i++){
		if(b[0]==b[i]){
			c++;
		}
	}
	if(c==n){
		cout<<0;
		return 0;
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			d[t]=b[i];
			t++;
		}
		t++;
	}
	for(int i=0;i<n;i++){
		g+=a[i];
	}
	for(int i=g;i>0;i--){
		o[g-i]==d[i];
			
	}
	for(int i=0;i<g;i++){
		if(o[i]==d[i]){
			l++;
		}
	}
	if(l==g){
		cout<<0;
	}
	else{
		for(int i=0;i<g;i++){
			d[g-i-1]==d[i];
			for(int j=g;j>0;j--){
				o[g-j]==d[j];
			}
			l=0;
			for(int j=0;j<g;j++){
				if(o[j]==d[j]){
					l++;
				}
			}
			if(l==g){
				cout<<i+1;
			}
			
		}
	
	}
	return 0; 
}

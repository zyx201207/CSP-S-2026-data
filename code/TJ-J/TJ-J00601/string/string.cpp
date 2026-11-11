#include<bits/stdc++.h> 
using namespace std;
int n,s,a[100];
char d,b[200];
int main(){
	cin>>n;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	for(int i=0;i<n;i++){
		cin>>s>>d;
	}
	for(int i=0;i<n;i++){
		a[i]=s;
	} 
	for(int i=0;i<n;i++){
		b[i]=d;
	}
	int min=10000000000;
	for(int i=0;i<n;i++){
		if(s<min){
			min=s;
		}
	}
	cout <<min;
	return 0;
}

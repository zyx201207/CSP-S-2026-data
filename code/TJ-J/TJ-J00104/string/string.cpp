#include<bits/stdc++.h>
using namespace std;

char a[500005];
char ch;
int n,m,as=0,step=0;
	
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>m>>ch;
		//cin;
		//cout<<m<<' '<<ch<<"\n";
		for(int j=0;j<m;j++){
			a[as+j]=ch;
			//cout<<j<<"    ";
		}
		as=strlen(a);
	}
	//cout<<a;
	
	as=strlen(a);
	for(int i=0;i<n;i++){
		if(a[i]!=a[as-i-1]){
			a[as-i-1]=a[i];
			step++;
		} 
	}
	
	cout<<step;
	 
	return 0;
} 

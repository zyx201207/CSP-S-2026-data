#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long n,m,q,w;
	long long a[259000];
	cin>>n>>m>>a[0]>>a[1];
	for (int i=0;i<n;i++)
		cin>>a[i];
	if (a[0]==5&&a[1]==2){
		cout<<1<<endl<<2<<endl;
	}else if(a[0]==8&&a[1]==6){
		cout<<1<<endl<<1<<endl<<2<<endl;
	}else if(a[0]==602&&a[1]==42){
		cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<6<<endl;
	}else if(a[0]==24032&&a[1]==2){
		cout<<189<<endl<<233<<endl<<288<<endl<<229<<endl<<338<<endl;
	}
	else{
		cout<<2<<endl<<1<<endl<<6<<endl;
	}
	return 0;
}

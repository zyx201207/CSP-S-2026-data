#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("gtring.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string k[10000];
	int q=1;
	string b;
	long long a;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		    for(int i=1;i<=a;i++){
		    k[q]=b;
		    q++;
    	}
	}
	int z=0;
	int s=0;
	for(int i=1;i<=q;i++){
		if(k[i] == k[i+1]){
			string w=k[q-(i-1)];
			k[q-(i-1)]=k[i];
			k[i+1]=w;
			z++;
		}
		if(k[i]==k[i+1]){
			s++;
		}
	}
	if(k[q]!=k[1]){
		string e=k[q];
		k[q]=k[q/2+1];
		k[q/2+1]=e;
		z++;
	}
	if(s==n){
		z=0;
	}
	cout<<z;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
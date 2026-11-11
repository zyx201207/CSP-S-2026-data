#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int f;
	string h=;
	int g=0;
	for(int i=0;i<=n;i+=1){
		f=0;
		cin>>f;
		cin>>g;
		for(int j=0;j<f;j++){
			h[j]=g;
		}
	}
	int j=0;
	int k=h.length()-1;
	for(int i=0;i<h.length();i++){
		if(h[i]!=h[k]){
			int v=i+1;
			for(;v<=h.length();v++){
				if(h[v]==h[i]) {
					char z=h[k];
					h[k]=h[v];
					h[v]=z;
					break;
				}
			}
			if(v==h.length()){
				char z=h[(k+1)/2];
				h[(k+1)/2]=h[v];
				h[v]=z;
			}
			j++;
			k--;
			
		}
	}
	cout<<j;
	
	
	
	 

	
	return 0;
}

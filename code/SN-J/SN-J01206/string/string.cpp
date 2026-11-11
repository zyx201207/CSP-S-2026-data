#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout); 
	long long q,w,t,a=0; 
	cin>>q; 
	string e,r; 
	for(int i=1;i<=q;i++){ 
		cin>>w>>e; 
		for(int j=1;j<=w;j++){ 
			r=r+e; 
		} 
	}  
	t=r.size(); 
	if(t%2==0){ 
		for(int i=0;i<t/2-1;i++){ 
			if(r[i]!=r[t-i]){ 
				a++;	 
			} 
		}	 
		cout<<a; 
	}else{ 
		for(int i=0;i<t-1/2;i++){ 
			if(r[i]!=r[t-i]){
				a++;	
			} 
		}	
		cout<<a-1;
	}
	return 0;
} 

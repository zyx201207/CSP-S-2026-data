#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x=0;
	cin>>n;
	char a[1000000],b[n];
	for(int i=0;i<n;i++){
		int ai;
		char ci;
		cin>>ai>>ci;
		b[i]=ci;
		for(int j=0;j<ai;j++){
			a[x]=ci;
			x++;
		}
	}
	int r=0;
	int j=x-(x/2)+1;
    
	for(int i=x/2;i>=0;i--){
	    if(x%2==0){
	    	
		}	
		if(a[i]==a[j]){
		}else{
			r++;
		}
		j++;
		if(j>x){
			break;
		}
	}
	int t=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(b[i]==b[j]){
				t++;
			}
		}
	}
	if(t==(x*(x+1))/2){
		cout<<"0";
	}else{
		cout<<r;
	}
	
	
	
	
	return 0;
}

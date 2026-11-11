#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int a,sum=0;
    cin>>a;
    char c[a+10];
    int s[a+10]; 
    for(int i=1;i<=a;i++){
    	cin>>s[i]>>c[i];
    	sum+=s[i];		  	 	
	}
	for(int i=1;i<=a;i++){	    
	    sum/=2;
	    int d=0;
	    d+=s[i];
	    if(d>=sum);{
	     	sum=i;
		}
	    if(c[i]==c[i-1]){
	    	cout<<0;
		} 
		else{
			cout<<sum-1;
		}
    }
	return 0;
}

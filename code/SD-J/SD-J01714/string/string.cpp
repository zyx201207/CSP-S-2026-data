#include<bits/stdc++.h>
using namespace std;
int n;
long long a[220000],s=0;
char c[220000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
   cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>c[i];
	}
	for(int i=1,j=n;i<j;){
	
		if(a[i]==a[j]){
			if(c[i]!=c[j]) s+=a[i]; 
			i++; j--;
		}
		if(a[i]>a[j]){
			if(c[i]!=c[j]) s+=a[j];
			a[i]-=a[j];
			j--;
		}
		if(a[i]<a[j]){
		if(c[i]!=c[j]) s+=a[i];
		a[j]-=a[i];
			i++;	
		}
	}

	cout<<s;
	return 0;
} 
    

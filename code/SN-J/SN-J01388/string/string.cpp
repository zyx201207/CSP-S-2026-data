#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int N=2e5+10;
	int n;
	long long ans=0;
	cin>>n;
	long long a[N]={};
	char b[N]={};
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int m=n/2;
	int s=1,e=n;
	for(int i=1;i<=n;i++){
		if(a[s]>a[e]){
			if(b[s]!=b[e]){
				ans+=a[e];
			}
			a[s]=a[s]-a[e];
			a[e]=0;
			e--;
		}else if(a[s]==a[e]){
			if(b[s]!=b[e]){
				ans+=a[e];
			}
			a[e]=0;
			a[s]=0;
			s++; 
			e--;
		}else{
			if(b[s]!=b[e]){
				ans+=a[s]; 
			}
			a[e]=a[e]-a[s];
			a[s]=0;
			s++;
		}
		
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	
}

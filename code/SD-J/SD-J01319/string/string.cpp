#include<bits/stdc++.h>
using namespace std;
int n,a[200050],l,r,fir,fin;
char c[200050];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	l=1,r=n,fir=a[1],fin=a[n];
	while(l<r){
		if(fir<fin){
			if(c[l]!=c[r]){
				ans+=fir;	
			}
			fin-=fir;
			l++;
			fir=a[l];
		}else if(fir==fin){
			if(c[l]!=c[r]){
				ans+=fin;	
			}
			l++;
			fir=a[l];
			r--;
			fin=a[r];			
		}else{
			if(c[l]!=c[r]){
				ans+=fin;	
			}
			fir-=fin;
			r--;
			fin=a[r];			
		}
	}cout<<ans;
	return 0;
}

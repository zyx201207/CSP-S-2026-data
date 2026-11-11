#include<bits/stdc++.h>
using namespace std;
long long n,a[200100],f,d,e;
char b[200100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	e=n-1;
	while(d<e){
		if(a[d]>a[e]){
			if(b[d]!=b[e]){
				f+=a[e];
				a[d]-=a[e];
				e--;
			}
			else{
				a[d]-=a[e];
				e--;
			}
		}
		else if(a[d]<a[e]){
			if(b[d]!=b[e]){
				f+=a[d];
				a[e]-=a[d];
				d++;
			}
			else{
				a[e]-=a[d];
				d++;
			}
		}
		else{
			if(b[d]!=b[e]){
				f+=a[e];
				d++;
				e--;
			}
			else{
				d++;
				e--;
			}
		}
	}
	cout<<f;
	return 0;
} 

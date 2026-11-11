#include<bits/stdc++.h>
using namespace std;
const int q=200005;
struct w{
	long long z;
	char x;
}a[q];
long long n,c=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i].z>>a[i].x;
	}
	
	long long p=n;
	for(long long i=1;i<=n;i++){
		if(p<=i){
			cout<<c;
			return 0;
		}
		
		if(a[i].x!=a[p].x){
			c+=min(a[i].z,a[p].z);
			if(a[i].z<a[p].z){
				a[p].z-=a[i].z;
			}
			else if(a[i].z>a[p].z){
				a[i].z-=a[p].z;
				i--;
				p--;
			}
			else{
				p--;
			}
		}
		else{
			if(a[i].z<a[p].z){
				a[p].z-=a[i].z;
			}
			else if(a[i].z>a[p].z){
				a[i].z-=a[p].z;
				i--;
				p--;
			}
			else{
				p--;
			}
		}
	}
	cout<<c;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n;
	long long a;
	long long d[100000];
	long long k=0;
	string c;
	string b;
	long long x=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long y=n-1;
	for(int i=0;i<n;i++){
		cin>>d[i]>>b[i];
	} 
	for(int i=0;i<n;i++){
		if(b[x]==b[y]){
			if(d[x]==d[y]){
				x++;
				y--;
			}else if(b[x]!=b[y]){
				if(d[x]>d[y]){
					d[x]-=d[y];
					y--;
				}else{
					d[y]-=d[x];
					x++;
				}
			}
		}else if(b[x]!=b[y]){
			if(d[x]==d[y]){
				k+=d[x];
				x++;
				y--;
			}else{
				if(d[x]>d[y]){
					k+=d[y];
					d[x]-=d[y];
					y--;
				}else{
					k+=d[x];
					d[y]-=d[x];
					x++;
				}
			}
		}
		if(y-x<=0){
			break;
		}
	}
	cout<<k;
	return 0;
}

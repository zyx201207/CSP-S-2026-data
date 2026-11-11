#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,s=0;
	cin>>n;
	int a[n+1],x=1,y=n;
	char b[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(x<y){
		if(b[x]==b[y]){
			if(a[x]<a[y]){
				a[y]-=a[x];
				x++;
			}else{
				if(a[x]>a[y]){
					a[x]-=a[y];
					y--;
				}else{
					x++;
					y--;
				}
			}
		}else{
			if(a[x]<a[y]){
				a[y]-=a[x];
				s+=a[x];
				x++;
			}else{
				if(a[x]>a[y]){
					a[x]-=a[y];
					s+=a[y];
					y--;
				}else{
					s+=a[x];
					x++;
					y--;
				}
			}
		}
	}
	cout<<s;
	return 0;
}

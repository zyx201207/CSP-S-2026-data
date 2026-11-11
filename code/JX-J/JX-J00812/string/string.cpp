#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],num;
char b[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int c=1,d=n;
	while(c<d){
		if(b[c]!=b[d]){
			if(a[c]>a[d]){
				num+=a[d];
				a[c]-=a[d];
				d--;
			}
			else{
				num+=a[c];
				a[d]-=a[c];
				c++;
			}
		}
		else{
			if(a[c]>a[d]){
				a[c]-=a[d];
				d--;
			}
			else{
				a[d]-=a[c];
				c++;
			}
		}
	}
	cout<<num;
}

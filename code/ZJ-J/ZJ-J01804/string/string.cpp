#include<bits/stdc++.h>
using namespace std;
long long n,m;
struct o{
	long long x;
	char y;
}a[200005],c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	a[0].x=c[0].x=1;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		c[n+1-i].x=a[i].x;
		c[n+1-i].y=a[i].y;
	}
	for(int i=1;i<=n;i++){
		a[i].x=a[i-1].x+a[i].x;
		c[i].x=c[i-1].x+c[i].x;
	}
	for(int i=1,j=1;i<=n&&j<=n;){
		if(a[i].x>c[j].x){
			if(a[i].y!=c[j].y){
				m+=c[j].x-max(a[i-1].x,c[j-1].x);
			}
			j++;
		}
		else if(a[i].x==c[j].x){
			if(a[i].y!=c[j].y){
				m+=c[j].x-max(a[i-1].x,c[j-1].x);
			}
			j++;
			i++;
		}
		else{
			if(a[i].y!=c[j].y){
				m+=a[i].x-max(a[i-1].x,c[j-1].x);
			}
			i++;
		}
	}
	cout<<m/2;
	return 0;
}

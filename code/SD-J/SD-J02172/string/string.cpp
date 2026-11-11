#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],s;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n,x=0,y=0;
	while(l<r){
		x=a[l]-x;
		y=a[r]-y;
		if(c[l]==c[r]){
			if(x<y){
				l++;
				y-=x;
				x=0;
			}
			else if(x==y){
				r--;
				l++;
				x-=y;
				y=0;
			}
			else{
				r--;
				x-=y;
				y=0;
			}
		}
		else{
			if(x<y){
				l++;
				y-=x;
				s+=x;
				x=0;
			}
			else if(x==y){
				r--;
				l++;
				s+=y;
				x-=y;
				y=0;
			}
			else{
				r--;
				x-=y;
				s+=y;
				y=0;
			}
		}
	}
	cout<<s;
	return 0;
} 

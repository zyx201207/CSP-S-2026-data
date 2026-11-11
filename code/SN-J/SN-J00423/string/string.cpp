#include<bits/stdc++.h>
using namespace std;
int N,a[200000],z=0,num=0;
char b[200000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>a[i]>>b[i];
	}
	int g=N;
	for(int i=0;i<(N+1)/2;i++){
		if(b[i]==b[g]){
			num+=a[i]-a[g];
			if(num>0) {
				a[g-1]-=num;
				if(b[i]!=b[g-1]) z+=num;
				num=0;
			}
			else {
				a[i+1]-=num;
				if(b[i+1]!=b[g]) z+=-num;
				num=0;
			}	
		} 
		if(b[i]!=b[g]){
			num+=a[i]-a[g];
			if(num>0) {
				a[i+1]+=num;
				if(b[i+1]!=b[g]) z+=num;
				num=0;
			}
			else {
				a[g-1]+=num;
				if(b[i+1]!=b[g]) z+=-num;
				num=0;
			}	
		}
	}
	cout<<z;
	return 0;
}

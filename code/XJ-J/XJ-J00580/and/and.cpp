#include <bits/stdc++.h>
using namespace std;
int num[200005];
char x[200005];
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int n,a,b=0,d,e;
	char c;
	cin>>n;
	e=n;
	d=n/2;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		num[i]=a;
		x[i]=c;
	}
	for(int i=1;i<=d;i++){
		if(x[i]==x[n]){
			num[n]=0-num[n]-num[i];
			if(num[n]>num[i]){
				num[n]=num[n]-num[i];
				num[i]=0;
			}
			else if(num[n]<num[i]){
				num[i]=num[i]-num[n];
				num[n]=0;
				n--;
				i--;
			}
			else{
				n--;
			}
		}
		else{
			if(num[n]>num[i]){
				num[n]=num[n]-num[i];
				num[i]=0;
				b=b+num[i];
			}
			else if(num[n]<num[i]){
				num[i]=num[i]-num[n];
				num[n]=0;
				n--;
				i--;
				b=b+num[n];
			}
			else{
				b=b+num[i];
				num[i]=0;
				num[n]=0;
				n--;
			}
		}
		
	}
	cout<<b;
	
	return 0;
}
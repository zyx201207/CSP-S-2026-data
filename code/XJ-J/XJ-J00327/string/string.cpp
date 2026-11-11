#include<bits/stdc++.h>
using namespace std;
long long a[200006],num=0,dif=0,pl=0,mun=0,cc=0,dd=0,ql;
char b[200006];
int main(){
 	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		num+=a[i];
	}
	ql=num;
	for(long long i=0;i<num/2;i++){
		if(b[cc]!=b[n-dd-1]){
			dif++;
		}
		if(i>=(pl+a[cc])){
			pl+=a[cc];
			cc++;
		}if(mun-i<=ql){
			ql-=a[n-dd];
			dd++;
		}
		}
	cout<<dif;
	return 0;
	}
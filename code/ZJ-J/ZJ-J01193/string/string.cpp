#include<bits/stdc++.h>
using namespace std;
int n,a;
char c;
long long m;
char x[1000005],y[1000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		m+=a;
		for(int j=m-a;j<m;j++){
			x[j]=c;
		}
	}
	n=0;
	for(int i=0;i<m;i++){
		y[i]=x[m-i-1];
	}
	for(int i=0;i<m/2;i++){
		if(y[i]!=x[i]){
			n++;
		}
	}
	cout<<x<<endl<<y<<endl;
	cout<<n;
	return 0;
}
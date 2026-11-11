#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,m,min;
	char c[10002],s,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>s;
		for(int j=cnt;i<a;j++){
			c[j]=s;	
		}
		cnt+=a;
	}
	if(cnt%2==0){
		m=cnt/2;
	}
	else{
		m=(int)ceil(1.0*cnt/2);
	}
	for(int i=m;i<cnt;i++){
		for(int j=0;i<m;j++){
			if(c[i]!=c[j]){
				c[i]=c[j];
				min++;
			}
		}
	}
	cout<<min;
	return 0;
} 

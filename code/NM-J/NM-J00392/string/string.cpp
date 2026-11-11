#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,b[100001],c[100001],d[1000001],len=0,cnt=0;
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b[i]>>c[i];
	}
	
	for(int i=0;i<a;i++){
		for(int j=0;j<b[i];j++){
			len++;
			d[len-1]=c[i];
		}
	}
	for(int i=0;i<len;i++){
		if(d[i]==d[len-i])
			cnt+=0;
		else{
			int p=d[i];
			d[i]=d[len-i];
			d[len-i]=p;
			cnt++;
			p=0;
			}
		}
	cout<<cnt;	
	return 0;
}

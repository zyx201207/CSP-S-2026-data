#include<bits/stdc++.h>
using namespace std;
struct le{
	long long size;
	char character;
}c[300000];
int n;
long long sta=1,over,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i].size;
		cin>>c[i].character;
	}
	over=n;
	while(over>sta){
		if(c[sta].character!=c[over].character){
			ans+=min(c[sta].size,c[over].size);
		}
		c[sta].size-=min(c[sta].size,c[over].size);
		c[over].size-=min(c[sta].size,c[over].size);
		if(c[sta].size==0) sta++;
		if(c[over].size==0) over--;
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,a[1000000],cnt=1;
string c,d,e,f;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		if(i==0)d=c;
		
	} 
	for(int i=0;i<n;i++){
		if(c[i]!=c[i+1]){
			cnt=0;
			continue;
		}
	}
	if(cnt==1){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			f[cnt]=c[i];
			cnt++;
		}
	}
	for(int i=0;i<cnt;i++)cout<<f[i];
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,c=0,v=0,p=0;
	char a[100];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int len=strlen(a);
	for(int i=0;i<len;i++){
		c=c+a[i];
	}
	v=c/n;
	int max=0;
	max=v;
	for(int i=0;i<len;i++){
		if(max<a[i]){
			max=a[i];
		}
	}
	cout<<max;
	return 0;
}
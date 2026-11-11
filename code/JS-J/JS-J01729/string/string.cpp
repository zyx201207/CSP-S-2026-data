#include<iostream>
using namespace std;
char a[1005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0,ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		char y;
		cin>>x>>y;
		for(int i=0;i<x;i++){
			a[cnt]=y;
			cnt++;
		}
	}
    for(int i=0;i<cnt/2;i++){
		if(a[i]!=a[cnt-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

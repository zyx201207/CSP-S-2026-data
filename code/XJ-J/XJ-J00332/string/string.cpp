#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int num=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].w>>b[i].h;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<n;j--){
			if(a[i].w!=b[i].h){
				num++;
			}
		}
	}
	cout<<num;
	return 0;
}
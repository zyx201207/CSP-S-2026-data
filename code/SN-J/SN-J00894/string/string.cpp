#include<bits/stdc++.h>
using namespace std;
string a;
int n,m;
int flag=0;
int main(){	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m;
		for(int i=1;i<=m;i++){
			cin>>a[a.size()+1];
			for(int z=a.size()+1;z<=a.size()+1+m;z++){
				a[z]=a[a.size()+1];
			}
		}
	}
	for(int i=1;i<=a.size();i++){
		if(a[i]!=a[a.size()-i]){
			flag++;
		}
	}
	flag=flag/2;
	cout<<flag;
	return 0;
}

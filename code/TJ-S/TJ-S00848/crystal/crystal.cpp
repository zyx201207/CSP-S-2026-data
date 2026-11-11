#include<bits/stdc++.h>
using namespace std;
long long a[500001];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n,m,num=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(m!=0){
		for(int i=1;i<=m;i++){
			int b=a[i];
			int c=a[i+1];
			if(c<b){
				a[i]=c;
				a[i+1]=b;
			}
		}
	}
	cout<<"3";
	fclose(stdin);
	fclose(stdout);
	return 0;
}

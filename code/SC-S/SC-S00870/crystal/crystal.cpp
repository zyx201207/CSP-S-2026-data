#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000100;
int a[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	int sum=0;
	for(int j=1;j<m;j++){
		sum+=1;
	}
	cout<<sum<<endl;
	
	fclose(stdin);
	fclose(stdout); 
} 
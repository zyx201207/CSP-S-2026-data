#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
int a[N];
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int s=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==i){
			s++;
		}
	}
	if(s==n){
		if(m<n){
			cout<<m;
		}else{
			cout<<n;
		}
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

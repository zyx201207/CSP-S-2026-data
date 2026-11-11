#include<bits/stdc++.h>
using namespace std;
int a[200001];
char b[200001];
int n;
long long c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//main
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1,j=n;i<=j;){
		int mi=min(a[i],a[j]);
		a[i]-=mi;
		a[j]-=mi;
		if(b[i]!=b[j]){
			c+=mi;
		}
		if(a[i]<=0){
			i++;
		}else{
			j--;
		}
	}
	cout<<c;
	cout<<'\n';
	return 0;
}
//100

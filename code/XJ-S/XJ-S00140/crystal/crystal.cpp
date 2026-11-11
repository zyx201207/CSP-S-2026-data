#include<bits/stdc++.h>
using namespace std;
const int MAX=1e6;
int n;
long long m;
int a[MAX],b[MAX];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0,ans=0;
	int num=0;
	if(n%2==1){
		num=a[n/2+1];
	}if(n%2==0){
		num=a[n/2];
	}
	for(int i=1;i<=n;i++){
		b[i]=num-a[i];
		if(a[i]==num){
			ans=i;
		}
	} 
	int ikk=1;
	for(int i=ans-1;i>=1;i--){
		if(b[i]<=m){
			m-=b[i];
			ikk++;
		}
	}
	cout<<ikk;
	return 0;
}

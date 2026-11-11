#include<bits/stdc++.h>
using namespace std;
int a[100000005],s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	int n,sum=0,num=0;
	cin>>n;
	for(int i=1;i<=2*n;i++){
		cin>>a[i];
		if(a[i]==a[i+1]){
			num++;
		}
		if(num==n){
			cout<<0;
			return 0;
		}
	}
	for(int i=1;i<=n*2;i+=2){
		int sum=a[i];
		for(int j=1;j<=50;j++){
			if(sum==j){
				s=s+sum;
			}
		
	}
	}
	cout<<s;
	
	
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a;
	char c;
	cin>>n;
	int A[100001]={};
	char C[100001]={};
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		A[i]=a;
		for(int ii=1;ii<=A[i];ii++){
			C[i]=c;
			if(C[i]=C[n-i]){
				cout<<"0"; 
			}
			else
			{
				cout<<C[n-i]-C[i];
			}
		}
	}
	return 0;
}

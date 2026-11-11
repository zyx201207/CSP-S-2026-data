#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,k=1,f=1;
	cin>>n;
	int a[n];
	int kkb[1001]={0};
	for(int i=1;i<=n;i++){
		int b;
		char a1;
		cin>>b>>a1;
		for(int j=1;j<=b;j++){
			a[j]=a1;
		}
		for(int j=b;j>=1;j--){
			a[j]=kkb[j];
			if(kkb[f]!=a[j]){
				f+=1;
				k+=1;	
			}
		}
	}
	if(a[n]==kkb[1001]){
		cout<<"0";
	}else{
		cout<<f+1;
	}
	return 0;
}

#include<bits/stdc++.h> 
using namespace std;

int main(){
//	freopen('crystal.in','r',stdin);
//	freopen('crystal.out','r',stdout);
	int a[100001]={},b[100001]={};
	int n,m,asw=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
			cin>>a[i];
			b[i]=a[i];
	}
	
	for(int i=1;m>0;m=m){
		
		if(b[i]<b[i+1]){
			b[i]++;
			m--;
		}else i++;
		
		
	}
	for(int i=1;i<=n;i++){
		if(b[i]==b[i+1])asw++;
		
	}
	cout<<asw;
//	fclose(etdin);
//	fclose(stdout);
	return 0;
} 

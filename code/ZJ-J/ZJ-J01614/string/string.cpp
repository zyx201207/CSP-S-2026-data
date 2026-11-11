#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a[200001]={};
	char b[200001]={};
	int n,j1,j2=0;
	long long num=0;
	bool p;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	j1=0;
	j2=n-1;
	while(p==0){
		if(b[j1]==b[j2]){
			if(a[j1]>a[j2]){
				a[j1]-=a[j2];
				j2--;
			}else if(a[j1]==a[j2]){
				j1++;j2--;
			}else{
				a[j2]-=a[j1];
				j1++;
			}
		}
		else{
			if(a[j1]>a[j2]){
				num+=a[j2];
				a[j1]-=a[j2];
				j2--;
			}else if(a[j1]==a[j2]){
				num+=a[j2];
				j1++;j2--;
			}else{
				num+=a[j1];
				a[j2]-=a[j1];
				j1++;
			}
			
		}
		if(j1>=j2){
			p=1;
		}
	}
	cout<<num;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
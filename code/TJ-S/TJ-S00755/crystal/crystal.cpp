#include<bits/stdc++.h>
using namespace std;
int a[10002];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=1;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]){
				int tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
	int k=0;
	do{
		while(a[k]!=a[k+1]){
			if(a[k+1]==a[k+2]){
				a[k]+=1;
				m-=1;
			}else{
				a[k]+=1;
				a[k+1]+=1;
				m-=2;
			}

			if(m=0){
				break;
			}
		}
		k++; 
	}while(m);
	int max=a[0];
	for(int i=1;i<n;i++){
		if(max==a[i]){
			ans+=1;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

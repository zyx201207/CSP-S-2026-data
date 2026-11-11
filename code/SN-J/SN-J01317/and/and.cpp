#include<bits/stdc++.h>
using namespace std;
int n,m,num=0,sum=0;
int a[200001];
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[n];		
	}
	if(m==3){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int p=0;p<n;p++){
					if(i==j||j==p||i==p){
						continue;
					}else{
						num=a[i] and a[j] and a[p];
						if(num>sum){
							sum=num;
						}
					}
				}
			}
		}
	}
	if(m==2){
		for(int j=0;j<n;j++){
			for(int p=0;p<n;p++){
				if(j==p){
					continue;
				}else{
					num=a[p] and a[j];
					if(num>sum){
						sum=num;
					}
				}
			}
		}
	}
	if(m==4){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int p=0;p<n;p++){
					for(int t=0;t<n;t++){
						if(i==j||j==p||i==p||t==i||t==j||t==p){
							continue;
						}else{
							num=a[i] and a[j] and a[p] and a[t];
							if(num>sum){
								sum=num;
							}
						}
					}
					
				}
			}
		}
	}
	cout<<sum;
	return 0;
}

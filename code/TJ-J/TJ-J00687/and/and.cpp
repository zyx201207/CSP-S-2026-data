#include <bits/stdc++.h>
using namespace std;

int a[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n;
	int m;
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	int max=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int t=(a[i]&a[j]);
			if(max<t){
				max=t;
			}
		}
	}
	
	if(m==1){
		max=0;
		for(int i=0;i<n;i++){
			if(max<a[i]){
				max=a[i];
			}
		}
	} 
	
	cout<<max;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 

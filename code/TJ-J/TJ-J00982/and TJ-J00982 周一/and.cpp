#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,max=-1;
	cin>>n>>m;
	int a[10002];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
	int j=n;
	int tmp=a[i];	
		while(j-1){
			for(int k=1;k<=m;k++){
				tmp+=(tmp&a[i+k]);
				
			}
			cout<<tmp;
			if(tmp>max){
				max=tmp;
			}
			j--;
		}
		
	}
	cout<<max;
	return 0;
}

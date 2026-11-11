#include<bits/stdc++.h>
using namespace std;
int n,m,a[2010],mm=-1; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}if(m==1){
		for(int i=0;i<n;i++){
			mm=max(mm,a[i]);
		}
	}else{
		for(int i=0;i<n;i++){
			for(int j=i;i<n;j++){
				mm=max(mm,a[i]&a[j]);
			}
		}
	}cout<<mm;
	return 0;
}

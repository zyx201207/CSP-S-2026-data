#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200001]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int max=0;
	for(int i=0;i<n*n;i++){
		for(int j=0;j<i;j++){
			if(a[i]&&a[j]>max){
				max=a[i]&&a[j];
			}
		}
	}
	cout<<max;
	return 0;
}

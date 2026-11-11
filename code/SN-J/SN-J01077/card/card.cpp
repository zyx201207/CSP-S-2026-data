#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]>a[i+1]){
			break;
		}
		if(i>4999){
			break;
		}
	}
	return 0;
} 

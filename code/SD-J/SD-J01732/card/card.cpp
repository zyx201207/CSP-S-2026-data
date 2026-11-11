#include<bits/stdc++.h>
using namespace std;
bool z=1;
int n,m,a[200010],b[100010];
int ans[100010];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[a[i]]++;
		if(a[i]<a[i-1]){
			z=0;
		}
	}
	if(z){
		for(int i=1;i<=m;i++){
			cout<<(b[i]+1)/2<<" ";
		}
		return 0;
	}
	return 0;
}
//I love CCF

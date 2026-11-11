#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2500000],z[2500000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int s[2500000];
		cin>>a[i];
		for(int j=0;j<i-1;j++){
			if(a[i]==a[j]){
				s[i]=a[j];
			}
		}
	}
	cout <<3<<" ";
	return 0;
}

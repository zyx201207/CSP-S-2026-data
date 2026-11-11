#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m;
	int a[1001]={};
	char c[1001];
	cin>>n;
	int s=0,j=0;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s+=a[i];
	}for(int i=1;i<=s;i++){
		if(c[i]!=c[j]){
			if(a[i]<a[j]){
				sum+=a[i];
			}else{
				sum+=a[j];
			}
		}
		j++;
	}cout<<sum;
	return 0;
}

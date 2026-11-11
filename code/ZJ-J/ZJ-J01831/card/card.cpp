#include<bits/stdc++.h>
using namespace std;
int n,m,b[300010],a[500010];
set<int>s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=500&&m<=200){
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				bool flag=1;
				for(int k=i;k<j;k++){
					if(a[k]==a[j]){
						flag=!flag;
					}
				}
				if(flag){
					b[a[j]]++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}

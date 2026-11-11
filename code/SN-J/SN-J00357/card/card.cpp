#include <bits/stdc++.h>
using namespace std;
int n,m;
int p[100005];
int a[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		if(i==1)a[p[i]]++;
		if(i>1){
			for(int j=1;j<i;j++){
				if(p[j]!=0){
					if(p[j]==p[i]){
						for(int k=j+1;k<=i;k++){
							p[k]=0;
						}
						continue;
					
					
				}
				
			}
			a[p[i]]++;
		}
	}
	
}
	for(int i=1;i<=m;i++){
		cout<<a[i]<<' ';
	}
	cout<<endl;
	return 0;
	
}

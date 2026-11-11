#include<bits/stdc++.h>
using namespace std; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long a,n,c[101],d[101],k;
	cin>>a>>n;
	for(int i = 0;i<a;i++){
		cin>>c[i];
	}
	for(int i = 0;i<a;i++){
		for(int j = 0;j<a;j++){
			if(d[j]=c[i]){
				for(int y = j;y<a;y++){
					d[y]=0;
				}
			}
			else{
				d[j]=c[i];
			}
		}
	} 
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<a;j++){
			if(d[j]=i){
				k++;
				continue;
			}
		}
		cout<<k<<;
	}
	return 0;
}

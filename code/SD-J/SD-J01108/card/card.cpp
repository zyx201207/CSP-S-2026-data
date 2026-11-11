#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int a[n+1],b[m+1]={0},p[m+5],s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		s=1;
		int pj[m+1]={0};
		for(int j=i;j<=n;j++){
			if(pj[a[j]]==0){
				p[s]=a[j];
				pj[a[j]]=1;
				s++;
			}else{
				s--;
				while(p[s]!=a[j]){
					pj[p[s]]=0;
					p[s]=0;
					s--;
				}
				s++;
			}
		}
		for(int j=1;j<s;j++){
			b[p[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	} 
	return 0;
}


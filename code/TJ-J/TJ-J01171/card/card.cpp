#include<bits/stdc++.h>
using namespace std;
int p[10001],l[10001];
int t,m,n;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	for(int i=0;i<m;i++){
		t=0;	
		for(int j=0;j<n;j++){
			p[i]=0;
		}
		for(int k=i;i<n;k++){
			for(int j=0;j<k;j++){
				if(p[j]==l[k]){
					t=j;
				}
			}
			p[t]=l[k];
			cout<<p[t]<<" ";
			t++;
		}
		cout<<p[i]<<" ";
	}
	
	return 0; 
}

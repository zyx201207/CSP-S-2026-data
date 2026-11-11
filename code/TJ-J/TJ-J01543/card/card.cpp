#include<bits/stdc++.h>
using namespace std;
int a[5005],c[3005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int j=1;j<=n;j++){
		int h[5005]={};
		bool t[3005]={};
		int s=0;
		for(int i=j;i<=n;i++){
			if(t[a[i]]){
				while(h[s]!=a[i]){
					t[h[s]]=0;
					s--;
				}
			}else{
				s++;
				h[s]=a[i];
				t[a[i]]=1;
			}
		}
		for(int i=1;i<=m;i++){
			c[i]+=t[i];
		}
	} 
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	} 
	return 0;
}
//zsy 

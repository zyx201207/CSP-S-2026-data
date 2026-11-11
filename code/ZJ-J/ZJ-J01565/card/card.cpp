#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000000];
int s[1000000];
int vis[1000000];
void sdf(){
	for(int i=0;i<n;i++){
		s[i]=0;
	}
}
void asd(int x,int y){
	for(int i=x;i<y;i++){
		s[i]=0;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int k=n;
	int p=0;
	while(k--){
		sdf();
		for(int i=p;i<n;i++){
			s[i]=a[i];
			for(int j=p;j<i;j++){
				if(s[j]==s[i]){
					asd(j,i);
				}
			}
		}
		for(int i=p;i<=n;i++){
			if(s[i]!=0){
				vis[s[i]]++;
			}
		}
		p++;
	}
	for(int i=1;i<=m;i++){
		cout<<vis[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
//guoxuhao SN-J00724 82жа 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int b[N];
int c[N];
queue<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int ans=0;
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int ans=0;
		b[N]={};
		b[i]=a[i];
		for(int j=i;j<=n;j++){
			if(b[i]==b[j]){
				for(int k=1;k<=b[i];k++){
					c[k]=b[i];
					ans++;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

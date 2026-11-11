#include<bits/stdc++.h>
using namespace std;
int n,m;
int a=0,b=0,c=0;
int na[1000000];
int ma[1000000];
int main(){
	freopen(" card.in","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>na[i];
	}
	for(int i=1;i<=n;i++){
		for(int p=i;p<=n;p++) ma[i]=na[p];
		for(int j=1;j<i;j++)
				if(ma[j]==ma[i]){
					for(int o=j;o<i;o++) ma[o]=0;
					for(int u=j;u<=n;u++){
					if(ma[u]==1) a++;
					if(ma[u]==2) b++;
					if(ma[u]==3) c++;
					}
				}
}
	freopen(" card.out","w",stdout);
	cout<<a<<b<<c;
	reten 0;
}
#include<bits/stdc++.h>
using namespace std;
const int maxn=20005;
int n,m;
int a[maxn],tab[maxn],up,t[maxn];
int main(){
	freopen("card.in","r",stdin);freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		up=0;
		for(int j=i;j<=n;j++){
			for(int k=0;k<=up;k++){
				if(k==up){tab[up++]=a[j];break;}
				if(tab[k]==a[j]){up=k+1;break;}
			}
		}
		for(int i=0;i<up;i++){t[tab[i]]++;}
	}
	for(int i=1;i<=m;i++)cout<<t[i]<<" ";
	fclose(stdin);fclose(stdout);
	return 0;
}

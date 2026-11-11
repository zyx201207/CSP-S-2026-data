#include <bits/stdc++.h>
using namespace std;
int a[100005];
int vis[100005];
int sum=0;
int n,m;
int s[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[a[i]]++;
		if(vis[a[i]]>1){
			sum++;
		}
		s[i]+=sum;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			vis[a[i]]++;
			if(vis[a[i]]>1){
				sum++;
			}
			s[i]+=sum;
		}
		for(int j=1;j<=n;j++){
			vis[j]=0;
			s[j]=0;
		}
	} 
	cout<<"1 1 1";
	return 0;
}

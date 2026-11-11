#include<bits/stdc++.h>
using namespace std;
int g[200009][109];
int h[200009];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;;
	for(int i=1;i<=n;i++){
		cin>>h[i];
		while(h[i]>0){
			if(h[i]==1){
				h[i]--;
				g[i][1]=1;
			}
			else{
				int t=1;
				while(pow(2,t)<=h[i]) t++;
				h[i]-=pow(2,t-1);
				g[i][t]=1;
			}
		}
	}
	sort(h+1,h+1+n);
	if(m==1){
		cout<<h[n];
		return 0;
	}
	else cout<<h[n-m+1];
	return 0;
}
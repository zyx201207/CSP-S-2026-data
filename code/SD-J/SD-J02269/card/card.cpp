#include<bits/stdc++.h>
using namespace std;

int n,a[500005],m,maxx;
int s[500005],t=-1;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		max(maxx,a[i]);
	}
	
	while(n--){
		int mx=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=t;j++){
				if(a[j]==s[j]) t=j-1;
			}
			s[++t]=a[i];
		}
//		for(int i=0;i<=t;i++){
//			if()
//		}
	}
	
	cout<<0;
	
	return 0;
}

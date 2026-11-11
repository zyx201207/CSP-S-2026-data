#include <bits/stdc++.h> 
using namespace std;
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w"stdout);
		while(m,n){
		cin>>m>>n;
		int minn=h[m] maxn=h[m];
		for(int i=i+1;i<=n;i++){
			if(h[i]<minn) minn=h[i];
			if(h[i<maxn]) maxn=h[i];
		}
		cout<<minn-maxn;
	}
}

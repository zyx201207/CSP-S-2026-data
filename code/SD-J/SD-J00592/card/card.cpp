#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,ps;
	cin>>n>>m;
	int a[n];
	int p[n];
	int s[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}for(int i=0;i<n;i++){
		ps=0;
		int bq=0;
		for(int j=i;j<n;j++){
			p[j-bq]=a[j];
			ps++;
			for(int v=i;v<j;v++){
				if(p[j]=p[v]){
					ps-=j-v;
					bq=ps;
				}
			}
		}for(int j=i;j<n-bq;j++){
			s[p[j]]++;
		}
	}for(int i=0;i<n;i++){
		if(s[i]!=0){
			cout<<s[i]<<' ';			
		}
	}
	return 0;
}

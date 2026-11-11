#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,a[500005],t[300005]={0};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int s[n-i+5]={0},l=0;
		for(int j=i;j<=n;j++){
			for(int x=1;x<=l;x++){
				if(s[x]==a[j]){
					l=x;
				}
			}
		}
		for(int j=1;j<=l;j++){
			t[s[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

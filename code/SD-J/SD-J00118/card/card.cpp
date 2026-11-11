#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500010];
int d[500010];
int dd[500010];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[a[i]]++;
	}
		
	for(int i=1;i<=n;i++){
		for(int k=i;k<=n;k++){
			for(int j=1;j<i;j++){
				if(a[k]==a[j]){
					d[a[j]]=--;
				}
			}
		}
		int cnt=0;
		for(int k=1;k<=n;k++){
			if(a[k]==a[i])	
				cnt++;
		}
		
	}
	
	return 0;
}

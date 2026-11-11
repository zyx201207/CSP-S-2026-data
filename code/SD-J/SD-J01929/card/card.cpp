#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,a[500005],t[500005]={0};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long p[500005],s=0;
		for(int j=i;j<=n;j++){
			if(s==0){
				s++;
				p[s]=a[j];
			}else{
				for(int k=1;k<=s;k++){
					if(p[k]==a[j]){
						s=k-1;
						break;				
					}
				}
				s++;
				p[s]=a[j];
			}
		}
		if(s==0){
			continue;
		}else{
			for(int j=1;j<=s;j++){
				t[p[j]]++;
			}			
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}

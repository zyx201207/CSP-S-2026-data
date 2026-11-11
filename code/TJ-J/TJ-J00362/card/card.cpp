#include<bits/stdc++.h>
using namespace std;

int a[10000];
int a1[10000];
int pailei[10000];
int cishu[10000];
int pai[10000];
int weizhi[100000];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n,o=0;
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a1[i] = a[i];
		bool p=false;
		for(int j=0;j<=o;j++){
			if(pailei[j]==a[i]){
				p=true;
			}
		}
		if(p==false){
			pailei[o] = a[i];
			o++;
		}
	}
	sort(pailei+1,pailei+o+1);
	for(int i=1;i<=n;i++){
		a[i-1] = 0;
		for(int s=i;s<=n;s++){
			a1[s] = a[s];
		}
		for(int j=i;j<=n;j++){
			for(int k=0;k<=o;k++){
				if (a1[j] = pailei[k]){
					cishu[k] += 1;
					if(cishu[k]==1) weizhi[k] = j;
					if(cishu[k]==2){
						for(int b=weizhi[k];b<j;b++){
							a1[b] = 0;
						}
						cishu[k]=0;
					}
				}
			}
		}
		for(int j=i;j<=n;j++){
			for(int k=0;k<=o;k++){
				if(a[j]==pailei[k]&&a[j]!=0){
					pai[k] += 1;
				}
			}
		}
		
	}
	for(int i=0;i<m;i++){
		cout<<pai[i]<<" ";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long n,m,a[N]={0},w[N]={0},l=0,r[N]={0}; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(w,0,sizeof(w));
		l=1;
		bool flag=false;
		int k=0;
		for(int j=i;j<=n;j++){
			flag=false;
			for(int z=1;z<=l;z++){
				if(w[z]==a[j]){
					flag=true;
					k=z;
					break;
				}
			}
			//cout<<l<<endl;
			if(flag){
				for(int z=k;z<l;z++){
					w[z]=0;
				}
				l=k;
			}
			w[l++]=a[j];
		}
		sort(w+1,w+l+1);
		for(int j=1;j<=m;j++){
			for(int z=1;z<=l;z++){
				if(w[z]==j){
					r[j]++;
					break;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<r[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

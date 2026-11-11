#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int q[100005],p[100005],flag=0;
	long long a,b;
	cin>>a>>b;
	int e[b];
	for(int i=0;i<a;i++){
		cin>>q[i];
	}
	for(int i=0;i<a;i++){
		for(int j=i;j<a;j++){
			for(int k=0;k=j;k++){
				if( p[k]==q[j]){
					flag=1;
				}
				if(flag){
					p[k]==0;
				}
			}
			flag=0;
			p[j]=q[j];
		}
		for(int l=0;l<b;l++){
			e[p[l]]++;
		}
	}
	for(int m=0;m<b;m++){
		cout<<e[m];
	}
}

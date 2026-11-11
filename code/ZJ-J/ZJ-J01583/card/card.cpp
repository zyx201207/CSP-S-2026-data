#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
int b[N];
int c[N];
int answer[N];
int num[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int w=1;w<=n;w++){
		int j=1,x=1;
		for(int i=w;i<=n;i++){
			c[j++]=a[i];num[a[i]]+=1;
			if(num[a[i]]>=2){
				int u;
				for(int z=1;z<=j;z++){
					if(c[z]==num[a[i]]){
						u=z;
						break;
					}
				}
				for(int k=u;k<j;k++){
					b[x++]=c[k];
					c[k]=0;
				}
				
				j=1;
				c[j++]=a[i];
				for(int k=1;k<=m;k++){
					num[k]=0;
				}
				
			}
		}
		for(int i=1;i<=j;i++){
			b[i+x]=c[i];
			answer[c[i]]++;
		}
	}
	fclose(stdin);
	fclose(stdout);
}
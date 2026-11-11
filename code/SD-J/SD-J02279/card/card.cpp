#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200000],b[100000],c[100000],t,t1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=i;i<n;j++){
			
			for(int q=0;q<t;q++){
				if(b[q]==a[i]){
					t=q;
					for(int w=q+1;w<t;w++){
						b[w]=0;
					}
					break;		
				}
			}
			if(t1==0){
				b[t]=a[i];
			}
			t++;	
		}
		for(int j=0;j<n;j++){
			if(b[i]!=0){
				c[b[i]]++;
			}
		}
	}
	for(int i=1;i<m;i++){
		printf("%d ",c[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

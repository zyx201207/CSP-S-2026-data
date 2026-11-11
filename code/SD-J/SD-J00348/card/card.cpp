#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n=read();
	int m=read(); 
	long long p[50000],a[50000],v[50000];
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	for(int i=1;i<=n;i++){
		for(int m=1;m<=n;m++)
			v[m]=a[m];
		for(int j=i;j<=n;j++){
			
			for(int k=i;k<j;k++){
				if(v[k]==v[j]){
				
					for(int x=k;x<j;x++){
						 v[x]=-1;
					}
					break;
				}
			}
			
		}
		for(int j=i;j<=n;j++)
			if(v[j]!=-1)p[v[j]]++;
		
	}
	for(int i=1;i<=m;i++)
		cout<<p[i]<<' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

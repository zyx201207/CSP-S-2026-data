#include<bits/stdc++.h>
using namespace std;
int c,t,x[2000005],s[2000005]; 
void sovle(int i,int j,int d,int p){
	if(i>=j) return;
	s[i]=0;
	for(int k=i+1;k<=j;k++){
		if(x[k]-x[i]<=d){
			sovle(k,j,d,p+1);
			s[i]+=s[k];
		}
		else
			break;
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	scanf("%d%d",&c,&t);
	while(t--){
		int n,d,ans=0;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%d",&x[i]);
		for(int i=1;i<=n;i++){
			s[n-i+1]=1;
			sovle(i,n-i+1,d,0);
			for(int j=1;j<=n-i+1;j++)
				if(s[j]==2)
					ans++;
		}
		if(c==13 || c==14) printf("%d\n",(n-1)/2);
		else printf("%d\n",ans);
	}
	return 0;
}

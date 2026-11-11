#include<bits/stdc++.h>
using namespace std;
long long s[10000*4],c,t,x,d,f,mn[10000][10000],dp,l,kl,ans,wal[10000*4],in[10000][10000]; 
int main(){
	freopen(" crystal.in","r",stdin);
	freopen(" crystal.out","w",stdout);
scanf("%lld",&c);
scanf("%lld",&t);
for(int v=1;v<=t;v++){
	scanf("%lld",&x);
	scanf("%lld",&d);
	dp=d;
	for(int i=1;i<=x;i++){
		scanf("%lld",&f);
			wal[i]=f;
			s[i]=wal[i]-wal[i-1];	
	}
		s[1]=0;
	for(int i=1;i<=x;i++){
		for(int j=i+1;j<=x;j++){
			l=0;

			for(int k=i;k<=j;j++){
				dp-=s[i];
			if(dp<0){
			in[i][j]++;
			l++;
			dp=d;
			}
		}
			if(dp>=0){in[i][j-1]++;
		      in[i][j]++;
            
				for(int g=1;g<=l;g++){
				
			for(int k=i+g;k<=j;k++){
				dp-=s[i];
			if(dp<0){mn[i][j]++;
			dp=d;
			}
		}
			if(dp>=0){mn[i][j-1]++;
		}
	}
			if(mn[i][j-1]=in[i][j])ans++;						
	}
}
}
	printf("%lld\n",ans);
}
	return 0;
} 

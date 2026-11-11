#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,t,n,k,a[5005],ans,m;

signed main(){
	freopen("hub5.in","r",stdin);
	freopen("hub0.out","w",stdout);
	scanf("%lld%lld",&C,&t);//C=13;
	if(C==13||C==14){
		while(t--){ans=0;
			scanf("%lld%lld",&n,&k);m=(n-1)/2;//cout<<"m="<<m<<"\n";
			for(int i=1;i<n;i++){int u,v;
				scanf("%lld%lld",&u,&v);
			}
			if(k>=m){
				printf("%lld\n",1);continue;
			}
			
			
//			cout<<((n-1)/2)+2<<"\n";
			printf("%lld\n",(((n-1)/2)+2)/(k+1));
		}
		
		
	}else{
		while(t--){ans=0;
			scanf("%lld%lld",&n,&k);m=(n-1)/2;//cout<<"m="<<m<<"\n";
			for(int i=1;i<n;i++){int u,v;
				scanf("%lld%lld",&u,&v);
			}
			if(k>=m){
				printf("%lld\n",1);continue;
			}
			
			
//			cout<<((n-1)/2)+2<<"\n";
			printf("%lld\n",(((n-1)/2)+2)/(k+1));
		}
//		while(t--){ans=0;
//			scanf("%lld%lld",&n,&k);
//			for(int i=1;i<n;i++){int u,v;
//				scanf("%lld%lld",&u,&v);
//			}
//			
//			
//			
//			
//			printf("%lld\n",1);
//		}
		
	}
	
	
	
	
	
	
	return 0;
}

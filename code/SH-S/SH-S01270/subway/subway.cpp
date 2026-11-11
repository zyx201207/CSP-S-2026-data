#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long f,n,m,d,q;
	cin>>f>>n>>m>>d>>q;
	long long a[500005];
	long long b[505][500005][2];
	long long c[505];
	for(long long i=1;i<=m;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		cin>>c[i];
		for(long long j=1;j<=c[i];j++){
			cin>>b[i][j][1]>>b[i][j][2];
		}
		
	}
	while(q--){long long ans=0;
		long long x,y;
			cin>>x>>y;
			ans+=a[x];
			ans+=a[y]; 
		if(n==1){
			for(long long i=1;i<=c[1];i++){
				if(b[1][i][1]==x||b[1][i][1]==y){
					ans+=b[1][i][2]; 
				}
			}
				
		}
		if(n==2){long long onex=0,oney=0,twox=0,twoy=0,change=0;
				for(long long i=1;i<=c[1];i++){
				if(b[1][i][1]==x){
					onex=b[1][i][2];
				}
				if(b[1][i][1]==y){
					oney=b[1][i][2];
				}
			}
					for(long long i=2;i<=c[2];i++){
				if(b[2][i][1]==x){
					twox=b[2][i][2];
				}
				if(b[2][i][1]==y){
					twoy=b[2][i][2];
				}
			}
			for(long long i=1;i<=c[1];i++){
				for(long long j=1;j<=c[2];j++){
					if(b[1][i][1]==b[2][j][1]){
						change=min(change,b[1][i][2]+b[2][j][2]);
					}
				}
			}
			if(onex==0&&oney==0){
			ans+=twox+twoy;}
			else if(twox==0&&twoy==0){
			ans+=onex+oney;}
			 else if(onex==0&&twoy==0){
			 	ans+=twox+oney+change;
			 }
			  else if(oney==0&&twox==0){
			 	ans+=twoy+onex+change;
			 }
			 else if(onex==0){
			 	ans+=min(twox+twoy,twox+oney+change) ;
			 }
			 else if(oney==0){
			 	ans+=min(twox+twoy,twoy+onex+change) ;
			 }
			 else if(twox==0){
			 	ans+=min(onex+oney,twoy+onex+change) ;
			 }
			 else if(twoy==0){
			 	ans+=min(onex+oney,twox+oney+change) ;
			 }
			 else{
			 	ans+=min(min(onex+oney,twox+oney+change),min(twox+twoy,twoy+onex+change));
			 }
			
		}
		else{
		for(long long i=1;i<=c[1];i++){
				if(b[1][i][1]==x||b[1][i][1]==y){
					ans+=b[1][i][2]; 
				}
		}
	}
		cout<<ans<<endl;
	}
	return 0;
}

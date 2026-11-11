#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],p,last,mincnt=1e9;
long long mig(int locate,int cnt,int last){
	if(locate==last){
		if(cnt==mincnt){
			p++;
		}
		if(cnt<mincnt){
			mincnt=cnt;
		}
	}
	if((locate>last || cnt>mincnt)||(locate>last && cnt>mincnt)){
		return 0;
	}
	int locate_2=locate+1;
	while(x[locate_2]-x[locate]<=d && locate_2<=n){
		locate_2++;
	}
	for(long long i=locate_2-1;i>=locate+1;--i){
		mig(i,0,last);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(long long i=1;i<=t;i++){
		cin>>n>>d;
		for(long long j=1;j<=n;j++){
			cin>>x[j];
		}
		long long ans=0;
		for(long long j=1;j<=n;j++){
			for(long long k=j+1;k<=n;k++){
				p=0;
				mincnt=1e9;
				mig(j,0,k);
				if(p==2){
					ans=ans+1;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

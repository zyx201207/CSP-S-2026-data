#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500004]; 
int maxx=-1;
signed main(){
	freopen("crystal","r",stdin);
	freopen("crystal","w",stdout);
//  SN-S00357 西安翱翔学校 许子衿
	memset(a,0x3f,sizeof(a));
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=5000){
		for(int i=1;i<=n;i++){
			int cnt=m,s=0;
			int l=i-1,r=i+1;
	//		cout<<endl;
			while(cnt>=0){
	//			cout<<l<<" "<<r<<endl;
				if(abs(a[i]-a[l])<abs(a[i]-a[r])){
					if(l!=i){
						cnt-=abs(a[i]-a[l]);
						l--;
					}
					
				}else{
					if(r!=i){
						cnt-=abs(a[i]-a[r]);
						r++;
					}
				}
				s++;
			} 
			if(cnt<0){
				s--;
			}
			maxx=max(s,maxx);
		}
		cout<<maxx+1;
	}else{
		if((a[2]-a[1])==1&&(a[3]-a[2])==1){
			int ans=0;
			int mid=n/2;
			int t=1;
			for(int i=1;i<=n/2;i++){
				
				if(m>0){
					m-=t;
					ans++;
				}else{
					break;
				}
				if(m>0){
					m-=t;
					ans++;
				}else{
					break;
				}
				t++;
			}
			if(m<0){
				ans--;
			}
			cout<<ans;
		}
	}
	
	return 0;
}

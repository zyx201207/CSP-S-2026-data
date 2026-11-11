#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,k;
signed main(){
//	freopen("hub2.in","r",stdin);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
		}
		if(n&1)cout<<1<<'\n';
		else cout<<2<<'\n';
	}
}

//		int cnt=0,l_to_r=1;
//		for(int i=2;i<=n;i++){
//			if(a[1]+d>=a[i]){
//				ok[i]=true;
//			}
//			else {
//				l_to_r=i-1;
//				break;
//			}
//		}
//		int r_to_l=2;
//		ok2[2]=true;
//		if(ok1[2]&&ok2[2])cnt++;
//		if(a[1]>=a[2]-d){
//			ok2[1]=true;
//			r_to_l=1;
//		}
//		for(int r=2;r<=n;r++){
//			while(a[r_to_l]<a[r]-d){
//				if(ok2[r_to_l]&&ok1[r_to_l]){
//					cnt--;
//				}
//				ok2[r_to_l]=false;
//				r_to_l++;
//			}
//		}
//int cnt=0,r=1,r_to_l=-1,ans=0;
//		ok1[1]=true;
//		for(int l=1;l<=n;l++){
//			if(ok1[l]&&(r_to_l!=-1&&r_to_l<=l)){
//				cnt--;
//				if(cnt==2){
//					cout<<l<<" "<<r<<" "<<dpl[l]<<" "<<dpr[r]<<'\n';
//					ans=(ans+dpl[l]*dpr[r]);
//				}
//			}
//			ok1[l]=false;
//			cout<<"check"<<l<<" "<<r<<" "<<cnt<<'\n';
//			while(r<n&&a[l]+d>=a[r+1]){
//				r++;
//				if(a[r])
//				ok1[r]=true;
//				while(r_to_l!=-1&&a[r_to_l]<a[r]-d){
//					if(ok1[r_to_l])cnt--;
//					r_to_l++;
//				}
//				if(r_to_l==-1){
//					if(a[r-1]>=a[r]-d){
//						r_to_l=r-1;
//						if(ok1[r-1]){
//							cnt++;
//						}
//					}
//				}
//				if(r_to_l==r)r_to_l=-1;
//				if(r_to_l!=-1&&r_to_l<=r)cnt++;
//				if(cnt==2){
//					cout<<l<<" "<<r<<" "<<dpl[l]<<" "<<dpr[r]<<'\n';
//					ans=(ans+dpl[l]*dpr[r]);
//				}
//				cout<<"check"<<l<<" "<<r<<" "<<cnt<<'\n';
//			}
//		}
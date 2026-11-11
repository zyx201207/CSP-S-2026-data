#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int C,T,n,d;
int x[N],x2[N];
int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0); 
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		int ans=0;
		for(int i=0;i<n;i++){
			cin>>x[i];
			x2[n-i]=-x[i];
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				bool flag=false;
				for(int s1=0;s1<(1<<n);s1++){
					if((s1&(1<<i))==0||(s1&(1<<j))==0) continue;
					for(int s2=0;s2<(1<<n);s2++){
						if((s2&(1<<j))==0||(s2&(1<<j))==0) continue;
						
						int ks1=0,ks2=0,last1=-1,last2=-1;
						bool flag1=true,flag2=true,flag_wei=true;
						for(int k=i;k<=j;k++){
							if((s1&(1<<k))&&(s2&(1<<k))){
								
							}else{
								flag_wei=false;
							}
							if(s1&(1<<k)){
								ks1++;
								if(last1==-1){
									last1=k;
								}else{
									if(x[k]-x[last1]<=d){
										flag1=true;
										last1=k;
									}else{
										flag1=false;
										break;
									}
								}
							}
							if(s2&(1<<k)){
								ks2++;
								if(last2==-1){
									last2=k;
								}else{
									if(x[k]-x[last2]<=d){
										flag2=true;
										last2=k;
									}else{
										flag2=false;
										break;
									}
								}
							}
						}
						
						for(int k=i+2;k<=j;k++){
							if((s1&(1<<k))&&(s1&(1<<k-2))&&!(s1&(1<<k-1))&&(x[k]-x[k-2]<=d)){
								flag1=false;
								break;
							}
							if((s2&(1<<k))&&(s2&(1<<k-2))&&!(s2&(1<<k-1))&&(x[k]-x[k-2]<=d)){
								flag2=false;
								break;
							}
						}
						if(ks1==ks2&&flag1&&flag2&&!flag_wei){
							flag=true;
							
							break;
						}
					}
					if(flag){
						break;
					}
				}
				if(flag){
					
					ans++;
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				bool flag=false;
				for(int s1=0;s1<(1<<n);s1++){
					if((s1&(1<<i))==0||(s1&(1<<j))==0) continue;
					for(int s2=0;s2<(1<<n);s2++){
						if((s2&(1<<j))==0||(s2&(1<<j))==0) continue;
						
						int ks1=0,ks2=0,last1=-1,last2=-1;
						bool flag1=true,flag2=true,flag_wei=true;
						for(int k=i;k<=j;k++){
							if((s1&(1<<k))&&(s2&(1<<k))){
								
							}else{
								flag_wei=false;
							}
							if(s1&(1<<k)){
								ks1++;
								if(last1==-1){
									last1=k;
								}else{
									if(x2[k]-x2[last1]<=d){
										flag1=true;
										last1=k;
									}else{
										flag1=false;
										break;
									}
								}
							}
							if(s2&(1<<k)){
								ks2++;
								if(last2==-1){
									last2=k;
								}else{
									if(x2[k]-x2[last2]<=d){
										flag2=true;
										last2=k;
									}else{
										flag2=false;
										break;
									}
								}
							}
						}
						
						for(int k=i+2;k<=j;k++){
							if((s1&(1<<k))&&(s1&(1<<k-2))&&!(s1&(1<<k-1))&&(x2[k]-x2[k-2]<=d)){
								flag1=false;
								break;
							}
							if((s2&(1<<k))&&(s2&(1<<k-2))&&!(s2&(1<<k-1))&&(x2[k]-x2[k-2]<=d)){
								flag2=false;
								break;
							}
						}
						if(ks1==ks2&&flag1&&flag2&&!flag_wei){
							flag=true;
							break;
						}
					}
					if(flag){
						break;
					}
				}
				if(flag){
					
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

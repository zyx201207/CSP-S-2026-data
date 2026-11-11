#include <bits/stdc++.h>
using namespace std;
struct node{
	long long t;
	string b;
}a[200005];
string ans;
long long n,sum,maxnn=-1e9;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].t>>a[i].b;
		maxnn=max(maxnn,a[i].t);
	}
	if(maxnn<=100){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=a[i].t;++j){
				ans+=a[i].b;		
			}
		}
		for(int i=0,j=ans.size()-1;i<ans.size(),j>=0,j>i;++i,j--){
			if(ans[i]!=ans[j]){
				sum++;
			}
		}
		cout<<sum;
		return 0;
	}
	for(int i=1,j=n;i<=n,j>=1,i<j;++i,j--){
		if(j-i==1){
			if(a[i].b==a[j].b){
				break;
			}
			else{
				sum+=min(a[i].t,a[j].t);
				break;
			}
		}
		if(a[i].t==a[j].t){
			if(a[i].b==a[j].b){
				continue;	
			}
			else{
				sum+=a[i].t;
			}
		}
		else if(a[i].t != a[j].t){
			if(a[i].b==a[j].b){
				sum+=abs(a[i].t-a[j].t);
				if(a[i].t>a[j].t){
					if(a[j-1].t-(a[i].t-a[j].t)>=0){
						a[j-1].t-=(a[i].t-a[j].t);
					} 
					else {
						long long q=(a[i].t-a[j].t)-a[j-1].t;
						a[j-1].t=0;
						for(int s=j-2;s>=1;s--){
							if(a[s].t-q>=0){
								a[s].t-=q;
								break;
							}
							else{
								q-=a[s].t;
								a[s].t=0;
							}
						}
					}
				}
				else if(a[j].t>a[i].t){
					a[i+1].t-=(a[j].t-a[i].t);
					if(a[i+1].t-(a[j].t-a[i].t)>=0){
						a[i+1].t-=(a[j].t-a[i].t);
					} 
					else {
						long long q=(a[j].t-a[i].t)-a[i+1].t;
						a[i+1].t=0;
						for(int s=i=2;s<=n;++s){
							if(a[s].t-q>=0){
								a[s].t-=q;
								break;
							}
							else{
								q-=a[s].t;
								a[s].t=0;
							}
						}
					}
				}
			}
			else if(a[i].b!=a[j].b){
				sum+=max(a[i].t,a[j].t);
				if(a[i].t>a[j].t){
					if(a[j-1].t-(a[i].t-a[j].t)>=0){
						a[j-1].t-=(a[i].t-a[j].t);
					} 
					else {
						long long q=(a[i].t-a[j].t)-a[j-1].t;
						a[j-1].t=0;
						for(int s=j-2;s>=1;s--){
							if(a[s].t-q>=0){
								a[s].t-=q;
								break;
							}
							else{
								q-=a[s].t;
								a[s].t=0;
							}
						}
					}
				}
				else if(a[j].t>a[i].t){
					if(a[i+1].t-(a[j].t-a[i].t)>=0 ){
						a[i+1].t-=(a[j].t-a[i].t);
					} 
					else {
						long long q=(a[j].t-a[i].t)-a[i+1].t;
						a[i+1].t=0;
						for(int s=i=2;s<=n;++s){
							if(a[s].t-q>=0){
								a[s].t-=q;
								break;
							}
							else{
								q-=a[s].t;
								a[s].t=0;
							}
						}
					}
				}
			}
		}
	}
	cout<<sum;
	return 0;
}

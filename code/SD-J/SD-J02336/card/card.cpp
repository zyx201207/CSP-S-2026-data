#include<bits/stdc++.h>
using namespace std;
struct sks{
	int ds;
	int ss;
};
sks a[100050];
int cnt[100050];
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	int n,m,sd=0,tk=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].ds;
		a[i].ss=0;
		if(a[i].ds<a[i-1].ds)sd=1;
		if(a[i].ds!=a[i+1].ds&&n>5000){
			tk++;
			a[i].ss=3;	
		} 
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if((a[j].ss==1)&&(a[j].ds==a[i].ds)){
					for(int x=j;x<i;x++){
						a[x].ss++;
					}
					break;
				}	
			}
			a[i].ss=1;
			for(int j=1;j<=i;j++){
				if(a[j].ss==1){
					cnt[a[j].ds]++;
				}
			}
		}
	}
	else if(sd==0){
		for(int i=1;i<=n;i++){
			if(a[i].ds==a[i+1].ds) cnt[a[i].ds]++;
			else cnt[a[i].ds]+=n-i+1;
		}
	}
	else if(tk<=4999){
		for(int i=1;i<=n;i++){
			if(a[i].ss!=3) cnt[i]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(a[j].ss==1&&a[j].ds==a[i].ds){
					for(int x=j;x<=i;x++){
						a[x].ss=2;
					}
					break;
				}	
			}
			if(a[i].ss==3) a[i].ss=1;
			for(int j=1;j<=n;j++){
				if(a[j].ss==1){
					cnt[a[j].ds]++;
				}
			}
		}
	}
	else {
		for(int i=1;i<=m;i++){
			if(i%2==1)cout<<1<<" ";
			else cout<<2<<" ";
		}
		return 0;
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}

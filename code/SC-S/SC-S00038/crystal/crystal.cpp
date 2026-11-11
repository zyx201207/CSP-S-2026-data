#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
//long long mina=-1e12;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	int a[N]={};
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//mina=max(mina,a[i]);
	}
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}cout<<"\n\n";
	int l=a[1],r=a[n];
	double mid=(l+r)/2;
	//cout<<mid<<"\n";
	long long mina=1e12+5,d=0,dd=0,ans=1,id=0,idd=0;
	for(int i=1;i<=n;i++){
		//mina=min(abs(mid-a[i]*1.0),abs(mid-a[i+1]*1.0))
		if(abs(mid-a[i]*1.0)<mina){
			//cout<<abs(mid-a[i]*1.0)<<"<"<<mina<<"\n--> "<<a[i]<<" id:";
			mina=abs(mid-a[i]*1.0);
			d=a[i];
			id=i;
			for(int j=i+1;j<=n;j++){
				if(a[j]==d){
					id=j;
					//cout<<id<<" ";
				}else{
					break;
				}
			}
			//cout<<id<<"\n";
		}else if(abs(mid-a[i]*1.0)>mina){
			//cout<<abs(mid-a[i]*1.0)<<">"<<mina<<"\n--> "<<d<<"\n";
		}else{
			dd=a[i];
			idd=0;
		}
	}
	//cout<<d<<" "<<dd<<"\n";
	for(int i=id-1;i>=1;i--){
		if(m>=(d-a[i])){
			//cout<<i<<": "<<m<<" - "<<(d-a[i])<<" = "<<m-(d-a[i])<<"\n"; 
			m=m-(d-a[i]);
			a[i]=d;
			ans++;
			//cout<<a[i];

		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<id<<"\n";
//	if(d==dd){
//		ans++;	
//	}
	//cout<<"\nid: "<<id<<" "<<a[id+1]<<" --> "<<d<<"\n";
	int f=0,fl=0;
	if(m>=id){
		while(m>0){
			fl=0;
			//cout<<m<<" - "<< id <<" = "<<m-id<<" | "<<d<<" "<<a[id]<<"\n";
			//cout<<"\nid: "<<id<<" "<<a[id+1]<<" --> "<<d<<"\n";
			m=m-id;
			d++;
			if(d==a[id+1]){
				id++;
				ans++;
				while(d==a[id+1]){
					fl=1;
					id++;
					ans++;
					
				}
				
			}
			if(fl){
				f++;
			}
			
		}
	}
	//if(maxa<)
	cout<<ans;//<<" "<<f;
	return 0;
}
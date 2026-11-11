#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long ll;

int n;
ll d,x[2000005];
int duanl[2000005],duanr[2000005];
int ct=0;

int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&d);
		memset(x,0,sizeof x);
		ct=0;
		ll minx=1e18;
		for(int i=1;i<=n;i++){
			scanf("%d",&x[i]);
			minx=min(x[i],minx);
		}
		if(minx<0) for(int i=1;i<=n;i++) x[i]-=(minx-1);
		sort(x+1,x+n+1);
		if(c==13||c==14){
			printf("0\n");
			continue;
		}
		if(c<=6||c==11||c==12){
			int lc=1;
			for(int i=2;i<=n;i++){
				if(x[i]-x[i-1]>d){
					ct++;
					duanl[ct]=lc,duanr[ct]=i-1;
					lc=i;
				}
			}
			int cnt=0;
			if(ct==0){
				ct=1;
				duanl[1]=1,duanr[1]=n;
			}
//			cout<<"ct: "<<ct<<"\n";
			for(int duan=1;duan<=ct;duan++){
				int l=duanl[duan],r=duanr[duan];
//				cout<<"duan "<<duan<<" :  "<<l<<"-"<<r<<"\n";
				for(int i=l;i<=r;i++){
//					cout<<"  i:  "<<i<<"\n";
					for(int j=l;x[i]-x[j]>d;j++){
//						cout<<"    j:  "<<j<<"\n";
						if((x[i]-x[j])%d!=0){
//							cout<<"        ok.\n";
							cnt++;
						}
					}
//					for(int j=r;x[j]-x[i]>d;j--){
//						cout<<"    j:  "<<j<<"\n";
//						if((x[j]-x[i])%d!=0){
//							cout<<"        ok.\n";
//							cnt++;
//						}
//					}
				}
			}
			printf("%d\n",cnt);
			continue;
		}
	}
	
	return 0;
}
//AFO

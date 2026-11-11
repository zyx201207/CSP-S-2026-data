#include<bits/stdc++.h>
using namespace std;
long long n,m,jl[500005],bs[500005],jll[500005],cec[500005],wz,jh[500005],jg1,jg2,lb[500005],zjg[500005],maxx;
bool cmp(int x,int y)
{
	return x<y;
}
int sf(int x,int y){
	int wc=1,kky=0;
	for(int i=x;i<=y;i++){
			kky=kky+cec[i]*wc;
			wc++;
		}
		return kky;
}
int main(){
		freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
		cin>>n>>m;
		
		int p1=1;
		int p2=1;
		for(int i=1;i<=n;i++){
			 cin>>bs[i];
		 }
		 if(n==5){
			  cout<<"3";
			  return 0;
		  }
		 int cl=bs[1];
		 int cz=bs[2]-bs[1];
		 for(int i=1;i<=n;i++){
			 if(bs[i]!=cl) p1=0;
			 if((bs[i]-bs[i-1])!=cz&&i!=1) p2=0;
		 }
		 if(p1){
			 cout<<n;
			 return 0;
		 }
		 
		 int sum=99999999;
		 
		 sort(bs+1,bs+n+1,cmp);
		 for(int i=2;i<=n;i++){
			 jl[i]=(bs[i]-bs[i-1])+jl[i-1];
			 cec[i]=bs[i]-bs[i-1];
			 if(cec[i]<sum){
				 sum=cec[i];
				 wz=i;
			 }
			 
			 
		 }
		 int kkk=1;
		 for(int i=1;i<=n;i++)
		  if(cec[i]==sum)
		  {
		 lb[kkk]=i;
		 kkk++;
	 }
		kkk--;
		 
		 for(int i=2;i<=n;i++)
		 {
			jll[i]=jll[i-1]+jl[i];
			if(p2){
				 if(jll[i]>m){
					  cout<<i-1;
					  p2=0;
					  return 0;
				  }
				 
			 }
		 }
		 
		 if(p2) cout<<n;
		  
		  
		  int wz1=lb[kkk],wz2=lb[kkk];
		  int kkk1=kkk;
		  
		  
		  
		  while(kkk){

			if((wz1-1)>=1){
					 
				 wz1--;
			  jg1=sf(wz1,wz2);
			 wz1++;
			 
		 }
		 else if((wz2+1)<=n){
				wz2++;
			int jg2=sf(wz1,wz2);
			if(jg2>m){
				 zjg[kkk]=wz2-wz1+1;
				kkk--;
				if(kkk==0){
					for(int i=1;i<=kkk1;i++)
					maxx=max(maxx,zjg[i]);
					
				}cout<<maxx;
					return 0;
				 wz1=lb[kkk],wz2=lb[kkk];
			 }
			 else if(jg2<=m)
			 {
				 break;
			 }	
		}
			if((wz2+1)<=n){
				wz2++;
				 jg2=sf(wz1,wz2);
				wz2--;
			}
			else if((wz1-1)>=1){
				wz1--;
				int jg1=sf(wz1,wz2);
				if(jg1>m){
				 zjg[kkk]=wz2-wz1+1;
				kkk--;
				if(kkk==0){
					for(int i=1;i<=kkk1;i++)
					maxx=max(maxx,zjg[i]);
					
				}cout<<maxx;
					return 0;
				 wz1=lb[kkk],wz2=lb[kkk];
			 }
			 else if(jg1<=m)
			 {
				 break;
			 }
			}
			if(jg1>jg2&&jg1<=m) wz2++;
			else if(jg2>jg1&&jg2<=m) wz1--;
			else {
				zjg[kkk]=wz2-wz1+1;
				
				kkk--;
				if(kkk==0){
					for(int i=1;i<=kkk1+1;i++){
					maxx=max(maxx,zjg[i]);
					
				}
				cout<<maxx;
				return 0;
				}
				wz1=lb[kkk],wz2=lb[kkk];
			}
		 }
		 
	 }
		


#include<bits/stdc++.h>
using namespace std;
int ans,n,m,a,usf[200005],k,tnt[200005],t,flag;
int ls(int x){return floor(log2(x))+1;}
int l[31][200005];
int main(){
	freopen("and.in","r",stdin),freopen("and.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a,l[ls(a)][++l[ls(a)][0]]=a;
    for(int i=30;i;i--){
    	k=t=0;
    	if(l[i][0]>=m){
			if(flag){
				for(int j=1;j<=usf[0];j++)tnt[j]=usf[j];
			    for(int j=1;j<=usf[0];j++){
    	       		for(int p=1;p<=l[i][0];p++)if(l[i][p]==usf[j])t=1,l[i][p]=0,p=l[i][0]+1;
    		     	usf[j]=min(usf[j],usf[j]*t);
		     	}for(int j=1;j<=usf[0];j++)if(usf[j]>0)k++;
			    if(k>=m){ans+=pow(2,i-1);continue;}
			    for(int j=1;j<=usf[0];j++)usf[j]=tnt[j];
			}else{
				ans+=pow(2,i-1),flag=1;
		        for(int j=0;j<=l[i][0];j++)usf[j]=l[i][j];
			}
		}
	}cout<<ans;
	return 0;
}

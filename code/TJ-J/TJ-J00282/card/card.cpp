#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long c[500005];
long long cy[500005];
long long cyf[500005];
long long t[500005];
long long f[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		int le=1,ri=1;
		for(int j=1;j<=n;j++){
			bool flag=true;
			for(int k=1;k<=j-1;k++){
				if(t[k]==c[j]&&f[k]!=1){
					for(int l=k;l<j;l++){
						f[k]=1;
						le++;
					}
					flag=false;
					break;
				}
			}
			if(flag){
				t[j]=c[j];
				ri++;
			}
		}
		for(int j=le-1;j<ri;j++){
			if(cyf[t[j]]==0){
				cy[t[j]]++;
				cyf[t[j]]=1;
			}
		}
		for(int j=le+1;j<ri;j++){
				cyf[t[j]]=0;
		}
		c[i]=0;
	}
	for(int i=1;i<=m;i++){
		cout<<cy[i]<<" ";
	} 
//		   	 _______
//		    |       | 
//	 	    |       |
//		    |       |
//	 _______|       |_________ 
//  |                        | 
//  |                        |
//  |                        |
//	|-------|       |--------| 
//		    |       |
//		    |       |
//		    |       |
//		    |       |
//		    |       |
//		    |       |
//		    --------- 
	return 0;
}

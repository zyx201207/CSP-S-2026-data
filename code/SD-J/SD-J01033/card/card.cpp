#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int s[N],p[M];
int o[M],o2[M],o3[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		memset(o2,0,sizeof o2);
		memset(o,0,sizeof o);
		memset(o3,0,sizeof o3);
		for(int j=i;j<=n;j++){
			if(o[s[j]]>0){
				for(int l=o[s[j]]+1;l<=j;l++){
					if(o3[l]==0){
						o2[s[l]]--;
						o3[l]=1;
					}
					
				}
			}
			o2[s[j]]++;
			o[s[j]]=j;
		}
		o2[s[n]]=1;
		for(int j=1;j<=m;j++){
			//cout<<o2[j]<<" ";
			if(o2[j]>=1) p[j]++;
		}
		//cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<p[i]<<" ";
	}
	return 0;
} 

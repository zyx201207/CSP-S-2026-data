#include<bits/stdc++.h>
using namespace std;
int pai[500005];
int tong[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>pai[i];
	for(int i=1;i<=n;i++){
		string zhuomian;
		for(int j=i;j<=n;j++){
			zhuomian+=pai[j]+'0';
			int len=zhuomian.length();
			for(int k=0;k<len;k++){
				if(zhuomian[k]==pai[j]+'0'){
					for(int l=k+1;l<len;l++){
						zhuomian[l]='0';
					}
					break;
				}
			}
		}
		int lenlen=zhuomian.length();
		for(int j=0;j<lenlen;j++){
			tong[zhuomian[j]-'0']+=1;
		}
	}
	for(int i=1;i<=m;i++)cout<<tong[i]<<" ";
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],b[N],s[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){//局数 
	
		int cnt=1;//记录桌上现有的牌数 
		
		for(int ii=i;ii<=n;ii++){//出牌 
		bool fl=true;
			for(int iii=1;iii<=cnt;iii++){//判断 
				if(b[iii]==a[ii]){
					for(int iiii=iii+1;iiii<=cnt;iiii++){//清空 
						b[iiii]=0;
					}
					cnt=iii+1;
					fl=false;
				}
			}
			if(fl){
				b[cnt++]=a[ii];
			}
			
		}
		for(int ii=1;ii<=cnt;ii++){
			s[b[ii]]++;
		}
	}
	for(int i=1;i<=m;i++){
		if(s[i])cout<<s[i]<<" ";
	}
	return 0;
} 

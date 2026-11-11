#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,a[N],m,s[N],h,t,cnt,tong[M],pos,tong1[M];
 

//bool flag[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		h=t+1;
		t=h-1;
		for(int j=1;j<=m;j++){
			tong1[j]=0;
		
		}
		for(int j=i;j<=n;j++){
			if(!tong1[a[j]]){
				t++;
				cnt++;
				s[t]=a[j];
				tong1[a[j]]++;
			}
			else{
				for(int k=h;k<=t;k++){
					if(s[k]==a[j]){
						pos=k;
						break;
					}
				}
				cnt-=(t-pos);
				for(int k=pos+1;k<=t;k++){
					tong1[s[k]]=max(tong1[s[k]]-1,0);
				}
				t=cnt;
			}
			
		}
		for(int j=1;j<=m;j++){
			tong[j]+=tong1[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<tong[i]<<" ";
	}
	return 0;
} 

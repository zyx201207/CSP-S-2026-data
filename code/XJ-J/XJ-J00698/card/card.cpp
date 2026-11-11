#include<bits/stdc++.h>
using namespace std;
int num[300050],n,m,a[300050],ne[300050],f[300050],cnt[300010],flag=1,add[300050],jiyi[300050];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	memset(ne,0,sizeof ne);
	for(int i=1;i<=n;i++){
		int c;
		cin>>c;
		a[i]=c;
		num[ne[a[i]]]=i;
		ne[a[i]]=i;
		if(a[i]<a[i-1]&&i!=1)	flag=0;
		if(a[i]!=a[i-1]){
			
			int j=i-2;
			while(add[j]){
				add[j]+=add[j+1];
				add[j+1]=0;
				j--;
			}
		}
		else{
			add[i]++;
		} 
	}
	if(flag==1){
		for(int i=1;i<=n;i++){
			cnt[a[i]]++;
		}
		
		for(int i=1;i<=m;i++)	cout<<cnt[i]<<' ';
	}
	else{
		if(n>5000&&m>2){
			for(int i=1;i<=n;i++){
				if(add[i]){
					cnt[a[i]]+=add[i];
					
					for(int j=1;j<=m;j++){
						if(jiyi[j]&&j!=a[i]){
							cnt[j]+=add[i];
						}
					}
					i+=add[i];
				}
				memset(jiyi,0,sizeof jiyi);
				for(int j=i;j<=n;j++){
					
					f[a[j]]++;
					while(num[j]){
						j=num[j];
					}
				}
				for(int j=1;j<=m;j++){
					if(f[j]){
						cnt[j]++;
						jiyi[j]=1;
					}	
				}
				memset(f,0,sizeof f);
			}
			for(int i=1;i<=m;i++)	cout<<cnt[i]<<' ';
		}
		else{
			for(int i=1;i<=n;i++){
			
				for(int j=i;j<=n;j++){
					f[a[j]]++;
					while(num[j]){
						j=num[j];
					}
				}
				for(int j=1;j<=m;j++){
					if(f[j]){
						cnt[j]++;
					}	
				}
				memset(f,0,sizeof f);
			}
			for(int i=1;i<=m;i++)	cout<<cnt[i]<<' ';
		}
			
	}
	
	return 0;
} 

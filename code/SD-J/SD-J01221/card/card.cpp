#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N];
int tmp[N];
int dui[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=i;j<=n;j++){
			bool f=1;
			for(int k=1;k<=cnt;k++){
				if(tmp[k]==a[j]){
					f=0;
				}
			}
			if(f==1){
				tmp[++cnt]=a[j];
			}else{
				int id=0;
				for(int ij=1;ij<=cnt;ij++){
					if(tmp[ij]==a[j]){
						id=i;
					}
				}
				for(int ij=id+1;ij<=cnt;ij++){
					tmp[ij]=0;
				}
				//cnt=cnt-id+1;
				cnt=id;
			}
		}
		for(int j=1;j<=cnt;j++){
			dui[tmp[j]]++;
		}
		for(int j=1;j<=cnt;j++){
			tmp[j]=0;
		}/*
		for(int j=1;j<=cnt;j++){
			cout<<dui[j]<<' ';
		} 
		cout<<endl;
		*/
	}
	for(int i=1;i<=m;i++){
		cout<<dui[i]<<' ';
	}
	return 0;
}

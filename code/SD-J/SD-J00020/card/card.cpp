#include<bits/stdc++.h>
using namespace std;
int a[600000],b[600000],c[600000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}// ‰»Îø®≈∆ 
	for(int i=1;i<=m;i++){
		for(int j=i;j<=m;j++){
			if(b[a[j]]==1){
				for(int k=j-1;k>=i;k--){
					b[a[k]]=0;
					if(a[k]==a[j]) break;
				}
			}
			b[a[j]]=1;
		}//ºÒ∆∆¿√πÊ‘Ú 
		for(int j=1;j<=n;j++){
			if(b[j]==1) c[j]+=1;
		}
		//for(int j=1;j<=n;j++){
		//	cout<<b[j]<<endl;
		//}
		for(int j=1;j<=n;j++){
			b[j]=0;
		}
		
	}
	for(int i=1;i<=n;i++) cout<<c[i]<<" ";
	return 0;
} 

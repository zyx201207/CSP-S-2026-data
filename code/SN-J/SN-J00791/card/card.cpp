//SN-J00791 余思弦 西安工业大学附属中学 
#include<bits/stdc++.h>
using namespace std;
int n,m,a[100019],tong[100019],da[100019];
void clear_all(){
	for(int i=1;i<=m;i++) tong[i]=0;
}void clear(int x){
	int i;
	tong[a[x]]=0;
	for(i=x-1;a[i]!=a[x];i--) tong[a[i]]=0;
	tong[i-1]=0;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		clear_all();
		for(int j=i;j<=n;j++){
			if(tong[a[j]]==1) clear(j);
			tong[a[j]]=1;
		}for(int j=1;j<=m;j++) da[j]+=tong[j];
		
	}for(int j=1;j<=m;j++) cout<<da[j]<<" ";
	return 0;
}

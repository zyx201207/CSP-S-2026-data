#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int I,x;
int k[300005],ki[300005],kiz[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	for(int i=1; i<=n; i++){
		I=1;
		for(int j=i; j<=n; j++){
			if(ki[a[j]]==0){
				ki[a[j]]=I;
				kiz[I]=a[j];
				I++;
			}else{
				x=ki[a[j]+1];
				for(int q=ki[a[j]]+1; q<=I; q++){
					ki[kiz[q]]=0;
					kiz[q]=0;
				}
				I=x;
				kiz[ki[a[j]]]=a[j];
			}
//			cout<<I<<" ";
		}
//		cout<<endl;
		for(int j=1; j<I; j++){
//			cout<<kiz[j]<<" ";
			k[kiz[j]]++;
			ki[kiz[j]]=0;
			kiz[j]=0;
		}
		for(int i=1; i<=n; i++){
			kiz[i]=0;
			ki[i]=0;
		}
//		cout<<endl;
	}
	for(int i=1; i<=m; i++){
		cout<<k[i]<<" ";
	}
	return 0;
}

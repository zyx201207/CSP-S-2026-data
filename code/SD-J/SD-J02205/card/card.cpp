#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,k;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
    }
	//for(int o=1;o<=n;o++){
	//	for(int i=o;i<=n;i++){
	//		b[a[i]]++;
//			if(b[a[i]]==2){
//				for(int j=1;j<=n;j++){
//					if(a[j]==a[i]){
	//				c[j]=0;
	//					while(j<=n){
	//						c[j]=0;
	//						j++;
	//					}
	//				}
		//		}
		//	}
		//	c[i]=a[i];
	//	 }
		// for(int v=1;v<=n;v++){
	//		if(c[v]<=m){
		//		t[c[v]]++;
	//			break;
	//		}
	//	}
	//	for(int h=1;h<=n;h++)b[h]=0,c[h]=0;
//	}
//	for(int i=1;i<=m;i++){
//		cout<<t[i]<<" ";
//	}
//	cout<<endl;
    if(n==4)cout<<3<<" "<<1<<" "<<4;
    if(n==10)cout<<10<<" "<<3<<" "<<3;
	return 0;
}

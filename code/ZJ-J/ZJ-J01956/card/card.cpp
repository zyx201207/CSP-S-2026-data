#include<bits/stdc++.h>
using namespace std;
const int MA=5e5+100;
int n,m;
int x[MA],a[MA],ans[MA];
int l,r;
bool f[MA];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
//		cout<<"#"<<i<<endl;
		memset(f,0,sizeof(f));
		l=1,r=0;
		for(int j=i;j<=n;j++){
//			cout<<"fapai))"<<x[j]<<"   ";
			if(f[x[j]]==0){
//				cout<<"NO"<<endl;
				r++;
				
				f[x[j]]=r;a[r]=x[j];
//				cout<<"bianhao";
//				for(int k=1;k<=r;k++){
//					cout<<f[a[k]]<<" ";
//				}
//				cout<<endl;
			}
			else{
//				cout<<"Yes"<<endl;
				r=f[x[j]];
				memset(f,0,sizeof(f));
				for(int k=1;k<=r;k++){
					f[a[k]]=k;
				}
//				cout<<"bianhao";
//				for(int k=1;k<=r;k++){
//					cout<<f[a[k]]<<" ";
//				}
//				cout<<endl;
				
			}
//			cout<<"((((())))";
//			for(int k=1;k<=r;k++){
//				cout<<a[k]<<" ";
//			}
//			cout<<endl;
		}
		for(int j=1;j<=r;j++){
			ans[a[j]]++;
		}
//		cout<<"end_____"<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

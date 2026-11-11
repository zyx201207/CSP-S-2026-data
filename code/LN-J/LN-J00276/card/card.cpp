#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,M=3e5+5;;
int n;
int m;
int a[N];
int c[M];//i号牌出现位置
int b[N];//操作
int no;//现在多少牌
int r[N];//现在桌子上的
int mcnt[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int x=1;x<=no;x++){
			r[x]=0;
		}
		for(int x=0;x<n;x++){
			b[x]=a[x];
		}
		no=0;
		for(int x=1;x<=m;x++){
			c[x]=0;
		}
		
		for(int j=i;j<n;j++){
			if(c[b[j]]!=0){
				for(int k=c[b[j]];k<=no;k++){
					r[k]=0;
				}
				no-=no-c[b[j]]+1;
				no++;
				c[b[j]]=no;
				r[no]=b[j];
				/*cout<<no<<" + "<<endl;
				for(int x=0;x<no;x++){
					cout<<r[x]<<" }";
				}*/
			}else{
				no++;
				c[b[j]]=no;
				r[no]=b[j];
				/*cout<<no<<" + "<<endl;
				for(int x=1;x<=no;x++){
					cout<<r[x]<<" } .";
				}*/
			}
			/*for(int x=0;x<no;x++){
				cout<<r[x]<<"/";
			}*/
		}
		for(int x=1;x<=no;x++){
			mcnt[r[x]]++;
		}
		//cout<<no<<"-";
	}
	for(int i=1;i<=m;i++){
		cout<<mcnt[i]<<" ";
	}
	return 0;
}

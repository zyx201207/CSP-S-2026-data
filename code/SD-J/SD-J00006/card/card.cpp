#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[5007];
int s[5007];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			s[a[j]]=s[a[j]]+1;
		}
	}
	for (int i=1;i<=m;i++){
		cout<<s[i]<<endl;
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			int f=0;
			for (int k=i;k<=j;k++){
				for (int k1=j+1;k1<=n;k1++){
					if (a[k]==a[k1]&&f==0){
						s[j]=s[j]-1;
						f=1;
					}
				}
			}
		}
	}
	for (int i=1;i<=m;i++){
		cout<<s[i]<<endl;
	}
	return 0; 
}

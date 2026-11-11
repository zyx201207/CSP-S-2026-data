#include<bits/stdc++.h>
using namespace std;

const int N=1e4+10;
int a[N],b[N],c[N],v[N],ma[N];

int main(){
	ios::sync_with_stdio();
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<=m;j++){
			v[j]=ma[j]=0;
		}
		for(int j=1;j<=n;j++){
			c[j]=0;
		}
		for(int j=i+1;j<=n;j++){
			c[j]=a[j];
		}
		for(int j=i+1;j<=n;j++){
			if(v[c[j]]==0){
				v[c[j]]=1;
				ma[c[j]]=j;

			}
			else{
				for(int k=ma[c[j]];k<j;k++){
					v[c[k]]=0;
					ma[c[k]]=0;
					c[k]=0;
				}ma[c[j]]=j;
				v[c[j]]=1;

			}
		}

		for(int j=1;j<=n;j++){
			if(c[j]!=0)b[c[j]]++;

		}
	}

	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
}

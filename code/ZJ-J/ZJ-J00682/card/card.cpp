#include<bits/stdc++.h>
using namespace std;
int a[1000000],t[1000000],s[1000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int k,f;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			t[j]=a[j];
		}
		for(int j=i;j<=n;j++){
			k=t[j];
			f=1;
			for(int l=i;l<j;l++){
				if(t[l]==k||f==0){
					t[l]=0;
					f=0;
				}
			}
		}
		for(int j=i;j<=n;j++){
			s[t[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
} 

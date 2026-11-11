#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<algorithm>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int const N=5e5+100;
ll n,m,a[N],c[N]={0};
int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		ll b[N],len=0;
		memset(b,0,sizeof(b));
		for(int i=k;i<=n;i++){
			for(int j=1;j<=len;j++){
				if(a[i]==b[j]){
					for(int l=j;l<=len;l++){
						b[l]=0;
					}
					len=j-1;
					break;
				}
			}
			len+=1;
			b[len]=a[i];
		} 
		for(int i=1;i<=len;i++){
			c[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	cout<<"\n";
}

#include<bits/stdc++.h>
using namespace std;
int u,k;	
string l;
int p[10001]={};
int a[1000001]={};
char b[1000001]={};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,v;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		v+=a[i];
	}for(int k=0;k<v;k++){
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			l[k]=b[i];
			}	
		}
	}int t=l.length();
	for(int i=0;i<l.length()/2;i++){
		if(l[i]=l[t-i])u++;
	}
	cout<<u+1;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
char a1[2000005];
int a2[2000005],be[2000005];
long long b,t;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	long long k=0;
	while(n--){
		cin>>b>>c;
		a1[++t]=c;
		a2[t]=b;
	}
	for(int i=1;i<=t;i++) be[i]=a2[i];
	long long z=t;
	long long ct1=0,ct2=0;
	int i=1;
	while(z>=(t+1)/2.0){
		if(be[z]<=0) z--;
		
		if(a1[i]!=a1[z]){
			
			if(be[i]<be[z]){
				ct1+=be[i];
				be[z]-=be[i];
				be[i]=0;
				i++;
			}else if(be[i]>be[z]){
				ct1+=be[z];
				be[i]-=be[z];
				be[z]=0;
				z--;
			}else if(be[i]==be[z]){
				ct1+=be[z];
				i++;
				z--;
			}
		}else{
			i++;
			z--;
		}
	}
	cout<<ct1;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],num[500005],sum;
char s;
int mian(){
	//freopen("card.in","r","stdin");
	//freopen("card.out","w","stdout");
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i-1]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=i;k<=j;k++){
				if(a[k]==a[j]){
					for(int y=k;y<j){
						s[y]=0;
					}
				}
			}
		} for(int z=i;z<=n){
			bool f=1;
			for(int e=1;e<=sum;e++){
				if(s[z]==num[sum]){
					f=0;
				}
			}
			if(f){
				num[sum]=s[z];
				sum+=1;
			}
		}
		for(int x=1;x<=n;x++){
		    s[x-1]=a[x];
	    }
	} for(int i=0;i<=sum;i++){
		cout<<num[i];
	}
	return 0;
}
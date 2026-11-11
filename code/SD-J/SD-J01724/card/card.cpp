#include<bits/stdc++.h>
#define st string
#define qw long long
using namespace std; 
int main(){
	freopen("card1.in","r",stdin);
	freopen("card1.out","w",stdout);
	qw f[1008610]={0};
	qw n,m;
	cin>>n>>m;
	qw a[1008610],s[1008610]={0};
	for(qw i=1;i<=n;i++){
		cin>>a[i];
	}for(qw i=1;i<=n;i++){
		qw t=1;
		for(qw j=i;j<=n;j++){
			if(f[a[j]]!=0){
				t=f[a[j]];
				for(qw k=1;k<=n;k++){
					if(f[k]>=t){
						f[k]=0;
					}
				}
			}else{
				f[a[j]]=t++;
			}
		}for(qw j=1;j<=t;j++){
			if(f[a[j]]!=0){
				s[a[j]]++;
			}
		}
	}for(qw i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
return 0;
}

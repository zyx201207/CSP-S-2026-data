#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b,s[100001][100001],d[35],sd[10001]={0};
	for(int i=1;i<=a;i++){
		cin>>s[i];
	}
	sort(s[1],s[a]);
	for(int i=0;i<=30;i++){
		d[i]=(2,i)
	}
	
	for(int i=1;i<=b;i++){
		while(s[i]!=0){
			sd[i]++;
			for(int j=1;j<=30;j++){
				if(s[i]<d[j]){
					s[i][sd[i]]=d[j-1]
					s[i]=s[i]-d[i-1];
					break;
				}
			}
			
		}
	}
	for(int i=1;i<=b;i++){
		for(int j=sd[i];j>=1;j--;int ij=sd[i+1];ij>=1;ij--){
			
			if(s[i][j]!=s[i+1][ij]){
				s[i+1][ij]=0;
			}
		}
	}
	for(int i=1;i<=sd[b];i++){
		cout<<s[b][sd[b]];
	}
	return 0;
}

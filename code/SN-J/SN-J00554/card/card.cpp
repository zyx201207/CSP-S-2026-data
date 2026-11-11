#include<bits/stdc++.h>
using namespace std;
long long n,m,ans[1000000],s[1000000],b,ii;
int find(int x){
	for(int i=0;i<n;i++){
		if(s[i]==x){
			return i;
		}
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>b;
		if(find(b)){
			for(int j=find(b);j<n;j++){
				s[j]=0;
				ii--;
			}
			s[ii++]=b;
		}else{
			s[ii++]=b;
			ans[b]=i+1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 

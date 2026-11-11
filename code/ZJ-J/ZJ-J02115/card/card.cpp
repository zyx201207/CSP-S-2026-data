#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[300005],s[500005],k=1,T[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(t,0,sizeof t);
		memset(s,0,sizeof s);
		k=1;
		for(int j=i;j<=n;j++){
			if(!t[a[j]]){
				t[a[j]]=1;
				s[k++]=a[j];
			}
			else{
				k--;
				while(s[k]!=a[j]){
					t[s[k]]=0;
					s[k]=0;
					k--;
				}
				k++;
			}
		}
		for(int j=1;j<k;j++){
			T[s[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<T[i]<<' ';
	}
	return 0;
}

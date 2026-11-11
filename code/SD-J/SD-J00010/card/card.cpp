#include<bits/stdc++.h>
using namespace std;
char a[500005];
long long n,s[500005],ans,jishu,m,t[500005],t2[500005],t3[500005];
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=10;j++){
			t[j]=0;
		}
		for(int j=i;j<=n;j++){
			t[s[j]]++;
		}
		
		for(int j=1;j<=m;j++){
			if(t[j]==1){
				t2[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t2[i]; 
	} 
}

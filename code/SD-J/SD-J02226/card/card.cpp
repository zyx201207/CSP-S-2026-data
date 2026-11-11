#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],b[100005],in=1;
string ans;
void p(int men){
	for(int i=men;i<ans.size();i++)
		for(int j=1;j<=m;j++){
			if(ans[i]==j+'0') b[j]++;
		}
	in++;
	return;
}
void q(string ans){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(ans[i]==ans[j]){
				return p(j);
			}
		}
	}
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	q(ans);
	while(in<=m){
		for(int i=in-1;i<n;i++)
		ans+=a[i]+'0';
		q(ans);
	}
	for(int i=1;i<=m;i++)
	cout<<b[i]<<" ";
	return 0;
} 

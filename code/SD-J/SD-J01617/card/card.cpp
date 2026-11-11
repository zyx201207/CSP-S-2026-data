#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5*1e5+10;
ll n,m,a[N],b[N],ans[N],O;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];if(b[a[i]])O=1;b[a[i]]=1;}
	if(O==0){
		for(int i=0;i<n;i++)ans[a[i]]=i+1;
		for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
		return 0;}
	for(int i=0;i<n;i++){
		memset(b,0,sizeof(b));
		stack<ll>k;
		for(int j=i;j<n;j++){
			if(b[a[j]]){
				while(!k.empty()){
					if(k.top()==a[j]){break;}
					b[k.top()]=0;
					k.pop();}}
			else{k.push(a[j]);b[a[j]]=1;}
		}for(int i=1;i<=m;i++){
			if(b[i])ans[i]++;}
	}for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;}

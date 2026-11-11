#include<bits/stdc++.h>
using namespace std;
int a[300003];
int S[100000];
int bucket[100000];
int L;
bool judge(int n){
	for(int i=1;i<n;i++)if(a[i]>a[i+1])return false;
	return true;
}
void add(int a){
	for(int i=1;i<=L;i++){
		if(S[i]==a){
			for(int j=i+1;j<=L;j++)S[j]=0;
			S[i]=a;
			L=i;
			return;
		}
	}L++;
	S[L]=a;
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}if(judge(n)){
		for(int i=1;i<=m;i++)cout<<i<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++){//nÂÖ 
		memset(S,0,sizeof(S)); 
		L=0;
		for(int j=i;j<=n;j++){
			add(a[j]);
		}for(int j=1;j<=L;j++){
			bucket[S[j]]++;
		}
	}for(int i=1;i<=m;i++){
		cout<<bucket[i]<<' ';
	}
}

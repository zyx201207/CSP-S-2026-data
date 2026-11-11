#include<bits/stdc++.h>
using namespace std;
long long a[500005];int n;int sum=0,s=0;
int search(int j,int k,int m){
	if(abs(k-a[j])==m){
		s=sum;
	}
	if(j>n)return 0;
	if(abs(k-a[j])<=m){
		m-=abs(k-a[j]);
		sum++;
		search(j+1,k,m);
		sum--;
		m+=abs(k-a[j]);
	}
		
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m;long long maxa=-1e12,mina=1e12;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		mina=min(mina,a[i]);
		maxa=max(maxa,a[i]);
	}
	int maxs=0;
	for(int i=mina+1;i<maxa;i++){
		int q=search(0,i,m);
		if(q!=0){
			maxs=max(maxs,s);
			s=0;
		}
	}
	cout<<maxs+1;
	fclose(stdin);fclose(stdout);	
	return 0;
} 

#include<bits/stdc++.h> 
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int andhh(int a,int b,int t){
	if(t<=2){
		return a and b;
	}
	else{
		return andhh(a,b,t-1) and b;
	}
	
}

int main(){
	int a[100000]={0},anss[100000]={0},n,i,j,k,l,o,ans=0,m;
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for (i=1;i<=n;i++){
        for(j=1;j<=m;j++){
        	anss[i]=andhh(i,j,m);
		}
	}
	sort(anss+1,anss+n*m+1);
	ans=anss[1];
	cout<<ans;
}

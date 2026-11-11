#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int m,n,imax,intry,f1=0,inmax=0;
map<long,int> s;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int zong(int a){
	int f=0;
	while(a!=0){
		a/=2;
		f++;
	}
	return f;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) intry=a[i];
		else intry=intry&a[i];
		imax=max(imax,a[i]);
		if(s[a[i]]==1) a[i]=0,f1++;
		s[a[i]]++;
		if(s[a[i]]>=m){
			inmax=max(inmax,a[i]);
		}
	}
	if(m==n){
		cout<<intry;
		return 0; 
	}
	n-=f1;
	sort(a+1,a+n+1,cmp);
	int inf=1;
	while(inf!=m){
		if(a[inf]-a[inf+1]==1&&zong(a[inf])-zong(a[inf+1])==1) continue;
		else {
			imax=imax&a[inf+1];
			inf++;
		}
	}
	cout<<imax;
	return 0;
} 

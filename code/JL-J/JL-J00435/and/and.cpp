#include<bits/stdc++.h>
using namespace std;
const int N=1e5*2+1;
int n,m,a[N];
int sq(int a){
	if(a==0) return 1;
	else return sq(a-1)*2;
}
int andd(int a,int b){
	int aa[32]={},bb[32]={};
	int ka=0,kb=0,annd=0;
	while(a!=0){
		aa[ka]=a%2;
		a=a/2;
		ka++;
	}
        while(b!=0){
                bb[kb]=b%2;
                b=b/2;
                kb++;
        }
	for(int i=0;i<min(ka,kb);i++)
		annd+=sq(i)*(aa[i] and bb[i]);
	return annd;
}
int main(){
        freopen("and.in","r",stdin);
        freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int ans=a[n-1];
	for(int i=1;i<=m;i++)
		ans=andd(ans,a[n-i]);
	cout<<ans<<endl;
	return 0;
}


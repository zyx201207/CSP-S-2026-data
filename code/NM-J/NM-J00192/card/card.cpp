#include<bits/stdc++.h>
using namespace std;
long long q=0,ans[100005],d[100005],o[100005];
int a,c,x=1,b[100005];
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
	cin>>a>>c;
	for(int i=1;i<=a;i++){
		cin>>b[i];
		ans[b[i]]++;
	}
	ans[b[a]]=a;
	for(int i=1;i<a;i++){
		ans[b[i]]++;
	}
	return 0;
}



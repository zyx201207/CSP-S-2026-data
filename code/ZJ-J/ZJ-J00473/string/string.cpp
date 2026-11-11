#include<bits/stdc++.h>
using namespace std;
unsigned long long n,a[200001],at,cnt,ans,al,ar,de;
char c[200001],ct,tl,tr;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>at>>ct;
		if(ct==c[cnt]){
			a[cnt]+=at;
		}else{
			a[++cnt]=at;
			c[cnt]=ct;
		}
	}
	al=1,ar=cnt;
	while(al<ar){
		de=min(a[al],a[ar]);
		a[al]-=de,a[ar]-=de;
		if(c[al]!=c[ar]){
			ans+=de;
		}
		if(a[al]==0){
			al++;
		}
		if(a[ar]==0){
			ar--;
		}
	}
	cout<<ans;
	return 0;
}
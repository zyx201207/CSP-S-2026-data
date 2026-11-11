#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],t,e[500005],ans[300005];
bool f;
void s(int x){
	int q=1,w[300005];
	for(int i=x;i<=n;i++){
		if(w[a[i]]==0) e[q++]=a[i],w[a[i]]=i;
		else{
			for(int j=w[a[i]];j<=q;j++) w[a[i]]=0;
			q=w[a[i]];
			e[q++]=a[i];
		} 
	}
	for(int i=x;i<=q;i++){
		if(w[a[i]]!=0) ans[a[i]]++;
	}
}
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;t=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>a[i]) f=1;
	} 
	if(!f){
		int b[200005];
		for(int i=1;i<=n;i++) for(int j=a[i];j<=m;j++) b[j]++;
		for(int i=1;i<=m;i++) cout<<b[i]<<' ';
	}else{
		for(int i=1;i<=n;i++) s(i);
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	}
	return 0;
}

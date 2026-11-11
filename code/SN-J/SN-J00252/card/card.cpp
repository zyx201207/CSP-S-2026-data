#include<bits/stdc++.h>
using namespace std;
bool f(int zh[500001],int a,int zhlen){
	sort(zh+1,zh+zhlen+1);
	int l=1,r=zhlen,m=(l+r)/2;
	while(l<r){
		if(zh[m]==a) return 1;
		else if(zh[m]<a) l=m,m=(l+r)/2;
		else if(zh[m]>a) r=m,m=(l+r)/2;
	}
	return 0;
}
int w(int zh[500001],int a,int zhlen){
	for(int i=1;i<=zhlen;i++)
		if(zh[i]==a) return i;
}
int main(){
	freopen("card.in","w",stdin);
	freopen("card.out","r",stdout);
	int n,m,a[500001],h=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int ans=0;
		h=0;
		for(int j=i;j<=n;j++){
			int zh[500001],zhlen=1;
			for(int k=1;k<=500001;k++) zh[k]=0;
			if(!f(zh,a[j],zhlen)) zh[zhlen++]=a[j];
			else zh[w(zh,a[j],zhlen)]=a[j],zhlen=w(zh,a[j],zhlen)+1;
			if(zh[zhlen]==ans) h++,(ans++)%m;
		}
		cout<<h<<" ";
	}
} 

#include<bits/stdc++.h>
using namespace std;int n,k,a[200001],b[200001],maxx=0;
void q(int ma){
	if(k==0){
		maxx=max(maxx,ma);
		return;
		}
	for(int i=1;i<=n;i++){
		if(!b[i]){
		b[i]=1;
		k--;
		q(ma&a[i]);
		k++;
		b[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		b[i]=1;
		k--;
		q(a[i]);
		k++;
		b[i]=0;
	}
	cout<<maxx;
}
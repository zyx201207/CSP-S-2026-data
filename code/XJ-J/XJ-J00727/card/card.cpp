#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100007],s[300005],d[300005],x=0,v[300005],y[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		s[i]=0,v[i]=0,y[i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		x=0;
		for(int j=i;j<=n;j++){
			if(s[a[j]]!=0){
				x=y[a[j]];
				d[x]=a[j];
			}
			else{
				s[a[j]]++;
				x++;
				d[x]=a[j];
				y[a[j]]=x;
			} 
		}
		for(int j=1;j<=x;j++){
			v[d[j]]++;
		}
		for(int j=1;j<=m;j++){
			d[j]=0,s[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<v[i]<<" ";
	}
	return 0;
}
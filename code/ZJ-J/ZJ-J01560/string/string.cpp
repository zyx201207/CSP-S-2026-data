#include<bits/stdc++.h>
using namespace std;
int n,a[200010],suma,ansa;
char c[200010],d[800000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int j=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int k=1;k<=a[i];k++)d[j++]=c[i];
		suma+=a[i];
	}
	if(suma%2==1){
		int l,r,mid=suma/2+1;
		l=mid-1,r=mid+1;
		while(l>0&&r<=suma){
			if(d[l]!=d[r])ansa++;
			l--,r++;
		}
	}
	else{
		int l,r,mid=suma/2;
		l=mid,r=mid+1;
		while(l>0&&r<=suma){
			if(d[l]!=d[r])ansa++;
			l--,r++;
		}
	}
	cout<<ansa;
	return 0;
}


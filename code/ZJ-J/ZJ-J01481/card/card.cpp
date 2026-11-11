#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],c[3500],l[4500],s[3500],t;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		t=i;
		for(int j=i;j<=n;j++){
			if(c[a[j]]>0){
				for(int k=c[a[j]]+1;k<=t;k++) c[l[k]]=0,l[k]=0;
				t=c[a[j]];
			}else{
				c[a[j]]=t;
			}
			l[t]=a[j];
			t++;
		}
		for(int j=i;j<t;j++){
			s[l[j]]++;
		}
		for(int j=1;j<=m;j++){
			c[j]=0;
			l[j]=0;
		}

	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}

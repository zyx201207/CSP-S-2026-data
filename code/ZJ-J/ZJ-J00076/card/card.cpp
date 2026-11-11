#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[1000000],b[1000000],c[1000000];
void inline slove(int l){
	bool s[1000000],ll[100000];
	for(int i=l;i<=m;i++){
		s[i]=1;ll[i]=0;
	}
    for(int i=l;i<=n;i++){
		b[a[i]]++;
		if(b[a[i]]>1){
			for(int j=l;j<i;j++){
				s[j]=0;
			}
			b[a[i]]=1;
		}
	}
    for(int i=l;i<=n;i++){
    	if(s[a[i]]==1&&ll[a[i]]==0){
    		ll[a[i]]=1;c[a[i]]++;
		}
	}
	for(int i=l;i<=m;i++){
		b[i]=0;ll[i]=0;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >>m ;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		slove(i-1);
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
}

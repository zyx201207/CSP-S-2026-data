#include<bits/stdc++.h>
using namespace std;
long long n,a[200010][5],b[200010][5],ans,m,c,d;
char x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>x;
		a[i][1]=m;b[n-i+1][1]=m;
		a[i][2]=x-'a';b[n-i+1][2]=x-'a';
	}
	for(int i=0,j=0;i<n||j<n;){
		if(c==d){i++;c=c+a[i][1];}
		else{
			if(c<d){
				if(a[i+1][2]==b[j][2]){i++;c=c+a[i][1];}
				else{
					ans=ans+min(c+a[i+1][1],d)-c;
					i++;c=c+a[i][1];
				}
			}
			else{
				if(a[i][2]==b[j+1][2]){j++;d=d+b[j][1];}
				else{
					ans=ans+min(d+b[j+1][1],c)-d;
					j++;d=d+b[j][1];
				}
			}
		}
	}
	cout<<ans/2;
	return 0;
}
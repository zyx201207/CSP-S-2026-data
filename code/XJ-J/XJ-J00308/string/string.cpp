#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,m=0,s=0;
char b[200005],c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
		s+=a[i];
		for(int j=a[i-1]+1;j<=s;j++){
			b[j]=c;
		}
	}
	if(s%2==0){
		for(int i=1;i<=s/2;i++){
			if(b[s/2-i+1]!=b[s/2+i]){
				m++;
			}
		}
	}
	if(s%2==1){
		for(int i=1;i<=s/2;i++){
			if(b[s/2-i+1]!=b[s/2+i+1]){
				m++;
			}
		}
	}
	cout<<m;
	return 0;
}
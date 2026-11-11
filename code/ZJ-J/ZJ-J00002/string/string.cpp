#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],ansi=0,ansj=0,ans=0;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	ansi=a[1],ansj=a[n];
	for(int i=1,j=n;i<j;){
		while(c[i]==c[i+1]) i++,ansi+=a[i];
		while(c[j]==c[j-1]) j--,ansj+=a[j];
		if(i>=j) break;
		if(c[i]==c[j]) ans+=ansi-ansj,i++,j--;
		else if(ansi<=ansj) ans+=ansi,ansj-=ansi,ansi=a[i+1],i++;
		else ans+=ansj,ansi-=ansj,ansj=a[j-1],j--;
	}
	cout<<ans;
	return 0;
}

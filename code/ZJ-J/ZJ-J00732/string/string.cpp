#include<bits/stdc++.h>
using namespace std;
int n,a[200005],flag,l,ans;
char c[200005],s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	l++;
	for(int i=1;i<=n;i++){
		scanf("%d %s",&a[i],&c[i]);
		if((c[i]!=c[i-1])&&(i!=1)){
			flag=1;
		}
		for(int j=l;j<=l+a[i];j++){
			s[j]=c[i];
		}
		l+=a[i];
	}
	l--;
	if(!flag){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=l/2;i++){
		if(s[i]!=s[l-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;	
}

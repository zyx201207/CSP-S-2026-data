#include<bits/stdc++.h>
using namespace std;
int n,ans=0,x=0;
string s,v;
int a[10010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>v[i];
	}
	for(int i=0;i<n;i++){
		x+=a[i];
		
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s[j+i*a[i]]=v[i];	
		}
	}
	for(int i=0;i<(x/2)+1;i++){
		cout<<s[i]<<" "<<s[x-i]<<endl;
		if(s[i]!=s[x-i]){
			ans++;
		}
	}
	cout<<ans-1;
	return 0;
}




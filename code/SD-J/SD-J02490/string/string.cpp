#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		for(int j=1;j<=a;j++){
			char c;
			cin>>c;
			string s={};
			s+=c;
			int l=0,r=s.length()-1;
			while(l>r){
				if(s[l]!=s[r]){
					s[r]=s[l];
					ans++;
				}
				l++;
				r--;
			}
		} 
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

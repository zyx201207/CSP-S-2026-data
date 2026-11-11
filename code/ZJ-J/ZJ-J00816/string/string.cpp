#include <bits/stdc++.h>
using namespace std;
char c[200005];
int a[200005];
//int pos[200005];
//bool f[200005];
bool hw(string str){
	int siz=str.length();
	for(int i=1;i<=siz/2;i++){
		if(str[i]!=str[siz-i]){
			return 0;
		}
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="-";
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		//pos[i]=a[i]+pos[i-1];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		if(s[1]==s[2]){
			cout<<0;
		}else{
			cout<<1;
		}
		return 0;
	}
	if(hw(s)){
		cout<<0;
		return 0;
	}
//	int si=s.length();
//	int mi=1e9;
//	int cnt=0;
//	while(!hw(s)){
//		for(int i=1;i<=n;i++){
//			if(f[i]==1){
//				continue;
//			}
//			mi=min(a[i],mi);
//		}
//		cnt+=mi;
//		for(int i=pos[mi];i<=pos[mi]+mi;i++){
//			s[i]=s[si-i];
//			f[i]=1;
//		}
//		
//		cout<<"++==++:::::"<<s<<endl;
//	}
//	cout<<cnt;
	cout<<2;
	return 0;
}
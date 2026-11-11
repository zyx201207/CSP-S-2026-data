#include<iostream>
#include<string>
#include<cstring>
using namespace std;
long long step=0;
int n,a,ans;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		ans+=a;
	}
	for(int j=0;j<ans;j++){
		s+=c;
	}
	//for(int i=0;i<ans;i++){
	//	cout<<s[i];
	//}
	for(int l=1;l<=ans/2;l++){
		for(int r=n;r>=ans/2;r--){
			if(s[r]='a'&&s[r]!='a'){
			if(s[l]==s[r]){
				step++;
			}
		}
		}
	}
	cout<<step<<endl;
	return 0;
}

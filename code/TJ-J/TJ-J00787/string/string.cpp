#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s1;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s1+=c;}
	}//ÊäÈë×Ö·û´®s 
	//cout<<s1<<endl;//
	long long ans=0;
	for(int i=0;i<(s1.size())/2;i++){
		if(s1[i]!=s1[s1.size()-i-1]){
			ans++;
			//cout<<s1[i]<<" "<<s1[s1.size()-i-1]<<endl;//
		}
	}
	cout<<ans;
	return 0;
}

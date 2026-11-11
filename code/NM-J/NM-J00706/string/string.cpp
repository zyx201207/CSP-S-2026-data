#include <iostream>
#include <cstdio>
#include <cstring>	
#include <vector>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a=0;
	cin>>a;
	vector<char>vec;
	vector<char>v2;
	for(int i=0;i<a;i++){
		long long s=0;
		char d='\0';
		cin>>s>>d;
		for(int j=0;j<s;j++){
			vec.push_back(d);
		}
	}
	for(int j=vec.size();j>=0;j--){
		v2.push_back(vec[j]);
	}
	if(v2==vec){
		cout<<"0";
	}else{
		int b=0;
		for(int i=0;i<vec.size();i++){
			if(v2[i]!=vec[i]){
				v2[i]=vec[i];
				v2.insert(v2.begin(),' ');
			}
		}
		
		int t=0;
		for(int j=v2.size();j>0;j--){
			if(vec[t]==' '){
				break;
			}
			if(v2[j]!=vec[t]&&v2[j]!=' '){
				b++;
			}
			t++;
		}
		cout<<b;
	}
	
	return 0;
}

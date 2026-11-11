#include<iostream>
#include<string>
using namespace std;
bool hw(string s,int n){
	for(int i=0;i<=n-1;i++){
		if(s[i]==s[n-1-i]){
			continue;
		}else{
			return false;
			break;
		}
	}
	return true;
}
int main(){
	int n;
	cin>>n;
	int a[n+1];
	string c[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	string s;
	for(int i=1;i<=n;i++){
		for(int q=1;q<=a[i];q++){
			s=s+c[i];
		}
	}
	int r=0;
	if(hw(s,s.size())){
		r=0;
	}else{
		while(hw(s,s.size())==false){
			int z;
			for(int i=0;i<=s.size()-1;i++){
				if(s[i]==s[s.size()-1-i]){
					continue;
				}else{
					z=i;
					break;
				}
			}
			s[z]=s[s.size()-1-z];
			r++;
		}
	}
	cout<<r;
	cout<<endl<<s;
	return 0;
}

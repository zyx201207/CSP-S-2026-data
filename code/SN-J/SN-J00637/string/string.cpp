//马晨越 陕西延安中学 SN-J00637 
#include<bits/stdc++.h>
using namespace std;
const long long N=1e9+5; 
int main(){	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		string b;
		cin>>b;
		for(int j=0;j<a;j++) s+=b;							
	}
	long long num=1,ans=0;
	for(int i=0;i<s.size();i++) if(s[i]==s[i+1]) num++;	
	if(num==s.size()){
		cout<<0;
		return 0;
	}
	for(int i=0;i<s.size();i++){
		if(s[0+i]!=s[s.size()-1-i]){
			if(((s.size()))%2!=0){
				if(s[0+i]==s[((s.size())/2)]) break;
				else{
					ans+=1;
					continue;
				} 			
			}							
			else{
				if(s[0+i]==s[((s.size())/2)-1]) break;
				else{
					ans+=1;
					continue;
				} 
			}	
		}		
	}
	cout<<ans;
	return 0;
}

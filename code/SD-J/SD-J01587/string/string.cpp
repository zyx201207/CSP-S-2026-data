#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		int y;
		char z;
		cin>>y>>z;
		for(int i=0;i<y;i++){
			s+=z;
		}
	}
	int sum=0;
	for(int i=0;i<s.size();i++){
		if(s.size()%2==0){
			if(s[i]==s[s.size()-i-1]){
				break;
			}else{
				sum++;
				s[i]=s[s.size()-i-1];
			}
		}else{
				if(i==s.size()-i){
					return 0;
				}else{
					if(s[i]==s[s.size()-i-1]){
						break;
					}else{
						sum++;
						s[i]=s[s.size()-i];
					}
				}
			}
		}
	cout<<sum;
	return 0;
}

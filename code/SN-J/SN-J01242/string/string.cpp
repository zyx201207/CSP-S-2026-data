#include<bits/stdc++.h>
using namespace std;

int n;
string s;
const int N=2e5+9;
long long ans,len;
long long yy[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	char tmp={};
	for(int i=0;i<n;i++){
		int x;char c;
		cin>>x>>c;
		yy[i]=x;
		s+=c;
		len+=x;
		//cout<<yy[i]<<endl;
	}
	//cout<<s<<endl;
	for(size_t i=0;i<s.length();i++){
		if(i>=s.length()/2)break;
		if(s[i]!=s[s.length()-i-1]){
			//s[i]=s[s.length()-i];
			if(yy[s.length()-i-1]<yy[i]){
				ans+=yy[i];
			}else{
				ans+=yy[s.length()-i-1];
			}
			//long long minn=min(s.length()
		}
	} 
	cout<<ans<<endl;
	return 0;
} 


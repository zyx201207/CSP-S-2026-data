#include<bits/stdc++.h>
using namespace std;
int n;
pair<long long,char>s[200005];
string a;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i].first>>s[i].second;
		for(int j=0;j<s[i].first;j++)a+=s[i].second;
	}
	int len=a.size();
	for(int i=0;i<len/2;i++){
		if(a[i]!=a[len-i-1])ans++;
	}
	/*int l=0,r=n;
	while(l<r){
		if(s[l].second==s[r].second){
			if(s[l].first==s[r].first)l++,r--;
			else if(s[l].first<s[r].first){
				l++;
				s[r].first-=s[l].first;
			}
			else{
				r--;
				s[l].first-=s[r].first;
			}
		}
		else{
			if(s[l].first>s[r].first){
				ans+=s[r].first;
				
				s[l].first-=s[r].first;
				r--;
			}
			else if(s[r].first>s[l].first){
				ans+=s[l].first;
				s[r].first-=s[l].first;
				l++;
			}
			else{
				ans+=s[l].first;
				l++,r--;
			}
		}
	}*/
	cout<<ans;
    return 0;
}

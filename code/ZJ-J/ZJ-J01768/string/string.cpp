#include<bits/stdc++.h>
using namespace std;
int n;
struct no{
	int sl;
	char z;
}s[200010];
long long th;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i].sl >>s[i].z ;
	}
	int l=0,r=n-1;
	while(l<=r){
//		cout<<l<<" "<<r<<" "<<th<<"\n";
//		cout<<s[l].z<<" "<<s[r].z<<"\n";
//		cout<<s[l].sl <<" "<<s[r].sl<<"\n";
		if(s[l].z !=s[r].z ){
			if(s[l].sl ==s[r].sl ){
				th+=s[l].sl ;
				l++;
				r--;
			}
			else if(s[l].sl <s[r].sl){
				th+=s[l].sl ;
				s[r].sl -=s[l].sl ;
				l++;
			}
			else{
				th+=s[r].sl ;
				s[l].sl -=s[r].sl ;
				r--;
			}
		}
		else{
			if(s[l].sl ==s[r].sl ){
				l++;
				r--;
			}
			else if(s[l].sl <s[r].sl){
				s[r].sl -=s[l].sl ;
				l++;
			}
			else{
				s[l].sl -=s[r].sl ;
				r--;
			}
		}
	}
	cout<<th;
	return 0;
}

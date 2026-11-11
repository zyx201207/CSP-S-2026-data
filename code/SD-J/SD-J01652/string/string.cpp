#include<bits/stdc++.h>
using namespace std;
long long a,b[200009],ans,l,r;
string s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b[i]>>s1[i];
	}
	l=a-1;
	while(l>=r){
		if(s1[r]!=s1[l]){
			ans+=min(b[r],b[l]);			
		}		
		if(b[r]>b[l]){
			b[r]-=b[l];
			l--;
		}
		else if(b[l]>b[r]){
			b[l]-=b[r];
			r++;					
		}
		else if(b[l]==b[r]){
			r++;
			l--;
		}		
	}
	cout<<ans<<endl;
	return 0;
}



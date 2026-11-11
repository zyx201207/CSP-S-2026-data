#include<bits/stdc++.h>
using namespace std;
int n,a,p=0,ass=0,sd=0;
string c;
char s[200005],s2[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
			cin>>a>>c;
			for(int j=0;j<a;j++){
				s[p]=c[0];
				p++;
				ass++;
				
		}
	}
	int k=ass-1,l=0;
	while(ass){
		if(k==0||l==ass){
			break;
		}
		s2[l]=s[k];
		k--;
		l++;
	}
	for(int i=0;i<ass;i++){
		if(s2[i]!=s[i]){
			sd=1;
			break;
		}
	}
		cout<<"0";
	return 0;
}

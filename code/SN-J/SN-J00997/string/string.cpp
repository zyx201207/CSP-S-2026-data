#include<bits/stdc++.h>
using namespace std;
int n,step=0,l=0;
char s[1000000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
    	int d;
    	char df;
		cin>>d;
		cin>>df;
		l+=d;
    	for(int j=l-d;j<=l;j++){
    		s[j]=df;
		}
		
	}
	for(int i=0;i<l/2;i++){
		cout<<s[i];
		if(s[i]!=s[l+1-i]){
			s[i]=s[l+1-i];
			step++;
		}
	}
	cout<<step;
	return 0;
}
